#include "stdafx.h"

// Simple test program to verify Vulkan renderer compilation
// This can be used to test our implementation without full engine dependencies

#include <iostream>

// Mock implementations for testing
void* HWRenderDevice = nullptr;
void* HWRenderContext = nullptr;
void* HWSwapchain = nullptr;
void* RenderTexture = nullptr;
void* RenderSRV = nullptr;
void* RenderRTV = nullptr;
void* RenderDSV = nullptr;
void* SwapChainRTV = nullptr;

// Mock message function
void Msg(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

// Test functions
extern bool CreateVulkan();
extern void DestroyVulkan();

int main() {
    std::cout << "Testing Vulkan renderer creation..." << std::endl;
    
    if (CreateVulkan()) {
        std::cout << "Vulkan renderer created successfully!" << std::endl;
        DestroyVulkan();
        std::cout << "Vulkan renderer destroyed successfully!" << std::endl;
        return 0;
    } else {
        std::cout << "Failed to create Vulkan renderer." << std::endl;
        return 1;
    }
}