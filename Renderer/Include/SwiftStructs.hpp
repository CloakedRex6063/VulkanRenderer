#pragma once
#include "SwiftEnums.hpp"
#include "expected"

struct GLFWwindow;
namespace Swift
{
    struct InitInfo
    {
        // Name for the app. Optional
        std::string appName{};
        // Name of the engine. Optional
        std::string engineName{};
        // Extent of the swapchain to be created. Mandatory
        glm::uvec2 extent{};
        // Native window handle. Mandatory
        // TODO: use std::variant to allow for linux support
        HWND hwnd{};
        // Use for wider support of GPUs and possibly better performance. Optional
        bool bUsePipelines{};
#ifdef SWIFT_IMGUI_GLFW
        // Window used to imgui initialisation
        GLFWwindow* glfwWindow{};
#endif

        InitInfo& SetAppName(const std::string_view appName)
        {
            this->appName = appName;
            return *this;
        }
        InitInfo& SetEngineName(const std::string_view engineName)
        {
            this->engineName = engineName;
            return *this;
        }
        InitInfo& SetExtent(const glm::uvec2 extent)
        {
            this->extent = extent;
            return *this;
        }
        InitInfo& SetHwnd(const HWND hwnd)
        {
            this->hwnd = hwnd;
            return *this;
        }
        InitInfo& SetUsePipelines(const bool usePipelines)
        {
            this->bUsePipelines = usePipelines;
            return *this;
        }
#ifdef SWIFT_IMGUI_GLFW
        InitInfo& SetGlfwWindow(GLFWwindow* window)
        {
            this->glfwWindow = window;
            return *this;
        }
#endif
    };

    struct DynamicInfo
    {
        glm::uvec2 extent{};

        DynamicInfo& SetExtent(const glm::uvec2 extent)
        {
            this->extent = extent;
            return *this;
        }
    };

    using ShaderHandle = u32;
    using BufferHandle = u32;
    using ImageHandle = u32;
    using SamplerHandle = u32;
    using ThreadHandle = u32;

    struct BoundingSphere
    {
        glm::vec3 center{};
        float radius{};

        BoundingSphere& SetCenter(const glm::vec3& center)
        {
            this->center = center;
            return *this;
        }
        BoundingSphere& SetRadius(const float radius)
        {
            this->radius = radius;
            return *this;
        }
    };

    struct BoundingAABB
    {
        glm::vec3 center{};
        float padding{};
        glm::vec3 extents{};
        float padding2{};
    };

    struct Plane
    {
        glm::vec3 normal{};
        float distance{};
    };

    struct Frustum
    {
        Plane topFace;
        Plane bottomFace;

        Plane leftFace;
        Plane rightFace;

        Plane nearFace;
        Plane farFace;
    };

    struct SamplerInitInfo
    {
        Filter minFilter;
        Filter magFilter;
        WrapMode wrapModeU;
        WrapMode wrapModeV;
        WrapMode wrapModeW;
        BorderColor borderColor;
        CompareOp comparisonOp;
        bool comparisonEnabled;
        SamplerMipmapMode mipmapMode;
        u32 minLod;
        u32 maxLod;

        SamplerInitInfo& SetMinFilter(const Filter value)
        {
            minFilter = value;
            return *this;
        }
        SamplerInitInfo& SetMagFilter(const Filter value)
        {
            magFilter = value;
            return *this;
        }
        SamplerInitInfo& SetWrapModeU(const WrapMode value)
        {
            wrapModeU = value;
            return *this;
        }
        SamplerInitInfo& SetWrapModeV(const WrapMode value)
        {
            wrapModeV = value;
            return *this;
        }
        SamplerInitInfo& SetWrapModeW(const WrapMode value)
        {
            wrapModeW = value;
            return *this;
        }
        SamplerInitInfo& SetWrapMode(
            const WrapMode u,
            const WrapMode v,
            const WrapMode w)
        {
            wrapModeU = u;
            wrapModeV = v;
            wrapModeW = w;
            return *this;
        }
        SamplerInitInfo& SetBorderColor(const BorderColor value)
        {
            borderColor = value;
            return *this;
        }
        SamplerInitInfo& SetComparisonOp(const CompareOp value)
        {
            comparisonOp = value;
            return *this;
        }
        SamplerInitInfo& SetComparisonEnabled(const bool value)
        {
            comparisonEnabled = value;
            return *this;
        }
        SamplerInitInfo& SetMipmapMode(const SamplerMipmapMode value)
        {
            mipmapMode = value;
            return *this;
        }
        SamplerInitInfo& SetMinLod(const u32 value)
        {
            minLod = value;
            return *this;
        }
        SamplerInitInfo& SetMaxLod(const u32 value)
        {
            maxLod = value;
            return *this;
        }
        SamplerInitInfo& SetLodRange(
            const u32 min,
            const u32 max)
        {
            minLod = min;
            maxLod = max;
            return *this;
        }
    };
} // namespace Swift