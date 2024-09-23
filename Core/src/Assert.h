#pragma once

#define FUSION_ASSERT(...) if (!(__VA_ARGS__)) { __debugbreak(); }
#define FUSION_VERIFY(...) if (!(__VA_ARGS__)) { __debugbreak(); }