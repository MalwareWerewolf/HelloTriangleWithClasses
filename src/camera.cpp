#include "camera.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f))
    , MovementSpeed(kSpeed)
    , MouseSensitivity(kSensitivity)
    , Zoom(kZoom)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    Camera::UpdateCameraVectors();
}

void Camera::UpdateCameraVectors()
{
}