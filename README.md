A simple triangle rendering with OpenGL on macOS using C++ classes.

## Requirements

1. Install glfw on macOS with homebrew:

```sh
$ brew install glfw
```

2. Use VSCode to compile the code or `make`
3. (Optional) If you get any errors because the `libglfw.3.dylib` is not loaded, use this command which is going to temporarily assign to the executable the correct dylib to use:

```sh
$ install_name_tool -change @rpath/libglfw.3.dylib /opt/homebrew/lib/libglfw.3.3.dylib build/app && ./build/app
```