# Vulkan Renderer for IX-Ray

This document describes the new Vulkan renderer implementation for IX-Ray.

## Overview

The Vulkan renderer (`xrRenderVK`) is a new rendering backend that provides native Vulkan support for IX-Ray. It follows the same architectural patterns as existing renderers (R1, R2, R4) but uses the modern Vulkan graphics API.

## Features

- **Native Vulkan Support**: Direct Vulkan API usage without compatibility layers
- **Cross-Platform Ready**: Designed to work on Windows and Linux (when build tools are available)
- **Modern Graphics Pipeline**: Uses Vulkan's explicit resource management and command recording
- **SPIR-V Shaders**: Uses compiled SPIR-V shaders for better performance

## Building

### Prerequisites

- **Vulkan SDK**: Install the LunarG Vulkan SDK from https://vulkan.lunarg.com/
- **CMake 3.20+**: Required for building
- **C++23 Compiler**: GCC 13.3+ or MSVC 2022+

### Build Options

The Vulkan renderer is automatically included in the build when `IXR_TEST_CI` is enabled (default for CI builds).

To build with Vulkan support:

```bash
mkdir build
cd build
cmake .. -DIXRAY_USE_R4=ON
make -j4
```

## Usage

### Selecting the Vulkan Renderer

The Vulkan renderer can be selected programmatically by setting the API level:

```cpp
// In engine initialization code
Device.InitRenderDevice(APILevel::Vulkan);
```

### Configuration

The Vulkan renderer uses the shader path `"vk\\"` for SPIR-V compiled shaders. Shaders should be compiled from HLSL to SPIR-V using appropriate tools.

### Debug Features

In debug builds, the Vulkan renderer automatically enables:
- Vulkan validation layers (`VK_LAYER_KHRONOS_validation`)
- Enhanced error reporting
- Resource tracking

## Architecture

### File Structure

```
src/Layers/xrRenderVK/
├── CMakeLists.txt           # Build configuration
├── stdafx.h                 # Precompiled header
├── stdafx.cpp               # PCH source
├── vk.h                     # Main renderer header
├── vk.cpp                   # Renderer implementation
├── xrRender_VK.cpp         # DLL entry point
└── test_vulkan.cpp         # Test utility
```

### Key Components

1. **CRender Class**: Main renderer implementation inheriting from `IRender_interface`
2. **VKDevice Structure**: Encapsulates Vulkan instance, device, and swapchain
3. **Resource Management**: Handles Vulkan buffers, images, and memory
4. **Command Recording**: Manages command buffers and synchronization

### Integration Points

The Vulkan renderer integrates with the engine through:

- **APILevel Enum**: Added `Vulkan` to the `APILevel` enum in `device.h`
- **Device Creation**: Extended `Device_create_render.cpp` with Vulkan support
- **CMake Build**: Added to the main build system in `src/CMakeLists.txt`

## Current Status

### Implemented ✅

- Basic Vulkan instance and device creation
- Swapchain management
- Core renderer interface implementation
- Build system integration
- Engine integration points

### In Progress 🚧

- Complete rendering pipeline implementation
- Resource management system
- Shader compilation pipeline
- Advanced rendering features

### Planned 📋

- Linux support (when build tools are available)
- Advanced lighting systems
- Post-processing effects
- Performance optimizations

## Troubleshooting

### Common Issues

1. **Vulkan SDK Not Found**
   - Ensure Vulkan SDK is installed and `VULKAN_SDK` environment variable is set
   - Verify CMake can find Vulkan: `find_package(Vulkan REQUIRED)`

2. **Validation Layer Errors**
   - Install Vulkan SDK with validation layers
   - In release builds, validation layers are disabled by default

3. **Build Errors**
   - Ensure C++23 compiler support
   - Check that all dependencies are properly installed

### Debug Information

The Vulkan renderer outputs debug information to the console:
- Device creation/destruction messages
- Buffer resize notifications
- Error reports (when validation layers are enabled)

## Contributing

When contributing to the Vulkan renderer:

1. Follow the existing code style and patterns from other renderers
2. Ensure minimal changes to core engine systems
3. Add appropriate error handling and validation
4. Update documentation for new features

## References

- [Vulkan Specification](https://www.khronos.org/vulkan/)
- [Vulkan Tutorial](https://vulkan-tutorial.com/)
- [LunarG Vulkan SDK](https://vulkan.lunarg.com/)
