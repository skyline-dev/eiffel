#pragma once

#include <eiffel/sl.h>

#include <stratosphere.hpp>
#include <string>
#include <map>

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

        std::map<std::string, SlPluginMeta> m_ActivePluginMetas;
        std::map<std::string, SlPluginSharedMemInfo> m_ActivePluginSharedMemInfos;

       public:
        static inline void SetPluginMeta(SlPluginMeta& pluginMeta) {
            GetInstance().m_ActivePluginMetas[pluginMeta.name] = pluginMeta;
        }

        static inline void SetPluginSharedMem(PluginName& name, SlPluginSharedMemInfo& sharedMemInfo) {
            GetInstance().m_ActivePluginSharedMemInfos[name.data()] = sharedMemInfo;
        }

        static ams::Result GetPluginMeta(SlPluginMeta* out_pluginMeta, PluginName& name);
        static ams::Result GetPluginSharedMemInfo(SlPluginSharedMemInfo* out_sharedMemInfo, PluginName& name);
    };

}  // namespace efl::core
