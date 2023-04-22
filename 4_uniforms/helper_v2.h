#ifndef HELPER_HEADER_FILE
#define HELPER_HEADER_FILE

#include <webgpu/webgpu.h>
#include <assert.h>

//  ------------------------------- Adapter------------------------------------------------------------------
struct AdapterUserData {
    WGPUAdapter adapter;
    bool requestEnded;
};

void onAdapterRequestEnded(WGPURequestAdapterStatus status, WGPUAdapter adapter, char const * message, void * pUserData);

WGPUAdapter requestAdapter(WGPUInstance instance, WGPURequestAdapterOptions const * options);

//  ------------------------------- Device------------------------------------------------------------------
struct DeviceUserData {
    WGPUDevice device;
    bool requestEnded;
};

void onDeviceRequestEnded(WGPURequestDeviceStatus status, WGPUDevice device, char const * message, void * pUserData);

WGPUDevice requestDevice(WGPUAdapter adapter, WGPUDeviceDescriptor const * descriptor);

void onDeviceError (WGPUErrorType type, char const* message, void* pUserData);

static const WGPULimits DEFAULT_WGPU_LIMITS = {
        .maxTextureDimension1D = 1,
        .maxTextureDimension2D = 1,
        .maxTextureDimension3D = 1,
        .maxTextureArrayLayers = 1,
        .maxBindGroups = 1,
        .maxBindingsPerBindGroup = 1,
        .maxDynamicUniformBuffersPerPipelineLayout = 1,
        .maxDynamicStorageBuffersPerPipelineLayout = 1,
        .maxSampledTexturesPerShaderStage = 1,
        .maxSamplersPerShaderStage = 1,
        .maxStorageBuffersPerShaderStage = 1,
        .maxStorageTexturesPerShaderStage = 1,
        .maxUniformBuffersPerShaderStage = 1,
        .maxUniformBufferBindingSize = 1,
        .maxStorageBufferBindingSize = 1,
        .minUniformBufferOffsetAlignment = 1,
        .minStorageBufferOffsetAlignment = 1,
        .maxVertexBuffers = 1,
        .maxBufferSize = 1,
        .maxVertexAttributes = 1,
        .maxVertexBufferArrayStride = 1,
        .maxInterStageShaderComponents = 1,
        .maxInterStageShaderVariables = 1,
        .maxColorAttachments = 1,
        .maxColorAttachmentBytesPerSample = 1,
        .maxComputeWorkgroupStorageSize = 1,
        .maxComputeInvocationsPerWorkgroup = 1,
        .maxComputeWorkgroupSizeX = 1,
        .maxComputeWorkgroupSizeY = 1,
        .maxComputeWorkgroupSizeZ = 1,
        .maxComputeWorkgroupsPerDimension = 1
};

void cCallback(WGPUErrorType type, char const* message, void* userdata);
void onDeviceLost(WGPUDeviceLostReason reason, char const* message, void* userdata);

WGPUShaderModule loadShaderModule(const char * path, WGPUDevice device);

typedef struct GeometryData {
    float *pointData;
    size_t pointDataSize;
    uint16_t * indexData;
    size_t indexDataSize;
} t_geometry_data;

bool loadGeometry(const char * path, t_geometry_data * geometry_data);

static const WGPUBindGroupLayoutEntry BIND_GROUP_DEFAULT = {
	.binding = 0,
	.buffer = {
		.nextInChain = NULL,
		.type = WGPUBufferBindingType_Undefined,
		.hasDynamicOffset = false,
		.minBindingSize = 0	
	},
	.sampler = {
		.nextInChain = NULL,
		.type = WGPUSamplerBindingType_Undefined		
	},
	.storageTexture = {
		.nextInChain = NULL,
		.access = WGPUStorageTextureAccess_Undefined,
		.format = WGPUTextureFormat_Undefined,
		.viewDimension = WGPUTextureViewDimension_Undefined	
	},
	.texture = {
		.nextInChain = NULL,
		.multisampled = false,
		.sampleType = WGPUTextureSampleType_Undefined,
		.viewDimension = WGPUTextureViewDimension_Undefined	
	},
	.visibility = WGPUShaderStage_None,
};

#endif