#pragma once

#include <eiffel/sl.h>

#include <stratosphere.hpp>
#include <string_view>
#include <unordered_map>

namespace efl::core {

    using PluginName = std::array<char, sizeof(SlPluginName)>;

    class PluginHandler {
       private:
        PluginHandler();
        PluginHandler(const PluginHandler&) = delete;
        ~PluginHandler();
        static inline auto& GetInstance() {
            static PluginHandler s_Instance;
            return s_Instance;
        }

        std::unordered_map<std::string_view, SlPluginMeta> m_ActivePluginMetas;
        std::unordered_map<std::string_view, SharedMemory> m_ActivePluginSharedMems;

       public:
        static inline void SetPluginMeta(SlPluginMeta& pluginMeta) {
            GetInstance().m_ActivePluginMetas[pluginMeta.name] = pluginMeta;
        }

        static inline void SetPluginSharedMem(PluginName& name, SharedMemory& sharedMem) {
            GetInstance().m_ActivePluginSharedMems[name.data()] = sharedMem;
        }

        static ams::Result GetPluginMeta(SlPluginMeta* out_pluginMeta, std::string_view name);
        static ams::Result GetPluginSharedMemInfo(SharedMemory* out_sharedMem, std::string_view name);
    };

}  // namespace efl::core
