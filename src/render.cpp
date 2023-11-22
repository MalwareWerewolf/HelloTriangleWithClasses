#include "render.hpp"
#include "shader.hpp"
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Render::renderLoop(GLFWwindow* window,
    Shader& shader,
    Texture& texture,
    const unsigned int VAO)
{
    shader.use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
    // or set it via the texture class
    shader.setInt("texture2", 1);

    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture.texture2);

        // create transformations
        glm::mat4 transform1 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        transform1 = glm::translate(transform1, glm::vec3(0.5f, -0.5f, 0.0f));
        transform1 = glm::rotate(transform1, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        // get matrix's uniform location and set matrix
        shader.use();
        unsigned int transformLoc = glGetUniformLocation(shader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform1));

        // render container
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // second container
        glm::mat4 transform2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        transform2 = glm::translate(transform2, glm::vec3(-0.5f, 0.5f, 0.0f));
        // transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        transform2 = glm::scale(transform2, glm::vec3(0.5f * sin(glfwGetTime()), 0.5f * sin(glfwGetTime()), 0.0f)); // Scale by 50%
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform2));

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Render::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
