#pragma once

#include "TypeInfo/Resolving.hpp"

template<>
struct std::hash<RED4ext::CName>
{
    std::size_t operator()(RED4ext::CName aKey) const
    {
        return aKey.hash;
    }
};

template<>
struct std::hash<RED4ext::TweakDBID>
{
    std::size_t operator()(RED4ext::TweakDBID aKey) const
    {
        return aKey.value;
    }
};

template<>
struct std::hash<RED4ext::ResourcePath>
{
    std::size_t operator()(RED4ext::ResourcePath aKey) const
    {
        return aKey.hash;
    }
};

template<>
struct std::hash<RED4ext::NodeRef>
{
    std::size_t operator()(RED4ext::NodeRef aKey) const
    {
        return aKey.hash;
    }
};

#ifdef __APPLE__
// macOS: size_t is `unsigned long` while the SDK ids convert to uint32_t/uint64_t (`unsigned long long`), so the
// generic specialization below is ambiguous for them.
template<>
struct std::hash<RED4ext::ent::EntityID>
{
    std::size_t operator()(RED4ext::ent::EntityID aKey) const
    {
        return static_cast<std::size_t>(aKey.hash);
    }
};
#endif

template<typename T>
requires std::is_class_v<T> && std::is_convertible_v<T, size_t> && Red::Detail::HasGeneratedTypeName<T>
struct std::hash<T>
{
    std::size_t operator()(T aKey) const
    {
        return static_cast<size_t>(aKey);
    }
};
