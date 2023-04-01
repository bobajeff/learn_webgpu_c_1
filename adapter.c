#include <GLFW/glfw3.h>
#include <webgpu/webgpu.h>
#include <stdio.h>
#include <glfw3webgpu.h>

    struct UserData {
        WGPUAdapter adapter;
        bool requestEnded;
    };

    void onAdapterRequestEnded(WGPURequestAdapterStatus status, WGPUAdapter adapter, char const * message, void * pUserData) {
        struct UserData * userData = (struct UserData *)pUserData;
        if (status == WGPURequestAdapterStatus_Success) {
            userData->adapter = adapter;
        } else {
            // std::cout << "Could not get WebGPU adapter: " << message << std::endl;
             printf( "Could not get WebGPU adapter: %s\n", message);
        }
        userData->requestEnded = true;
    };


WGPUAdapter requestAdapter(WGPUInstance instance, WGPURequestAdapterOptions const * options) {
    // A simple structure holding the local information shared with the
    // onAdapterRequestEnded callback.

    struct UserData userData =  {NULL, false};

    // Call to the WebGPU request adapter procedure
    wgpuInstanceRequestAdapter(
        instance /* equivalent of navigator.gpu */,
        options,
        onAdapterRequestEnded,
        (void*)&userData
    );

    return userData.adapter;
}

int main(int argc, char *argv[]) {
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = NULL;
    WGPUInstance instance = wgpuCreateInstance(&desc);
    if (!instance) {
        fprintf(stderr, "Could not initialize WebGPU!\n");
        return 1;
    }
    if (!glfwInit()) {
    printf("Could not initialize GLFW!\n");
    return 1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); 
    GLFWwindow *window = glfwCreateWindow(640, 480, "Learn WebGPU", NULL, NULL);
    if (!window) {
    printf("Could not open window!\n");
    glfwTerminate();
    return 1;
    }

    // std::cout << "Requesting adapter..." << std::endl;
    printf("Requesting adapter...\n");

WGPUSurface surface = glfwGetWGPUSurface(instance, window);

WGPURequestAdapterOptions adapterOpts = {};
adapterOpts.nextInChain = NULL;
adapterOpts.compatibleSurface = surface;

WGPUAdapter adapter = requestAdapter(instance, &adapterOpts);

// std::cout << "Got adapter: " << adapter << std::endl;
printf( "Got adapter: %p\n", adapter);

    while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}