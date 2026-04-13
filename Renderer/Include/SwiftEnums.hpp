#pragma once

namespace Swift
{
    enum class ImageFormat : uint8_t
    {
        eR16G16B16A16_SRGB,
        eR32G32B32A32_SRGB,
    };

    enum class ImageType : uint8_t
    {
        eReadWrite,
        eReadOnly,
    };

    enum class BufferType : uint8_t
    {
        eUniform,
        eStorage,
        eIndex,
        eIndirect,
        eReadback
    };

    enum class CullMode
    {
        eNone = VK_CULL_MODE_NONE,
        eFront = VK_CULL_MODE_FRONT_BIT,
        eBack = VK_CULL_MODE_BACK_BIT,
        eFrontAndBack = VK_CULL_MODE_FRONT_AND_BACK
    };

    enum class CompareOp
    {
        eNever = VK_COMPARE_OP_NEVER,
        eLess = VK_COMPARE_OP_LESS,
        eEqual = VK_COMPARE_OP_EQUAL,
        eLessOrEqual = VK_COMPARE_OP_LESS_OR_EQUAL,
        eGreater = VK_COMPARE_OP_GREATER,
        eNotEqual = VK_COMPARE_OP_NOT_EQUAL,
        eGreaterOrEqual = VK_COMPARE_OP_GREATER_OR_EQUAL,
        eAlways = VK_COMPARE_OP_ALWAYS,
    };

    enum class PolygonMode
    {
        eFill = VK_POLYGON_MODE_FILL,
        eLine = VK_POLYGON_MODE_LINE,
        ePoint = VK_POLYGON_MODE_POINT,
    };

    enum class Filter
    {
        eNearest = VK_FILTER_NEAREST,
        eLinear = VK_FILTER_LINEAR,
    };

    enum class WrapMode
    {
        eRepeat = VK_SAMPLER_ADDRESS_MODE_REPEAT,
        eMirroredRepeat = VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT,
        eClampToEdge = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        eClampToBorder = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
        eMirrorClampToEdge = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE,
        eMirrorClampToEdgeKHR = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR,
    };

    enum class BorderColor
    {
        eFloatTransparentBlack = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK,
        eIntTransparentBlack = VK_BORDER_COLOR_INT_TRANSPARENT_BLACK,
        eFloatOpaqueBlack = VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
        eIntOpaqueBlack = VK_BORDER_COLOR_INT_OPAQUE_BLACK,
        eFloatOpaqueWhite = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE,
        eIntOpaqueWhite = VK_BORDER_COLOR_INT_OPAQUE_WHITE,
    };

    enum class SamplerMipmapMode
    {
        eNearest = VK_SAMPLER_MIPMAP_MODE_NEAREST,
        eLinear = VK_SAMPLER_MIPMAP_MODE_LINEAR
    };
} // namespace Swift