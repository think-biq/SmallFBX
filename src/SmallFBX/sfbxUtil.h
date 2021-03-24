#pragma once

#ifdef _SFBX_DEBUG_LOG_
#define sfbxPrint(...) printf(__VA_ARGS__)
#else
#define sfbxPrint(...)
#endif

namespace sfbx {

// escape forbidden characters (e.g. " -> &quot;). return false if no escape is needed.
bool Escape(std::string& v);
std::string Base64Encode(span<char> src);

RawVector<int> Triangulate(span<int> counts, span<int> indices);

struct JointWeights;
struct JointMatrices;
bool DeformPoints(span<float3> dst, const JointWeights& jw, const JointMatrices& jm, span<float3> src);
bool DeformVectors(span<float3> dst, const JointWeights& jw, const JointMatrices& jm, span<float3> src);

} // namespace sfbx
