#include "plugin_handler.hpp"

#include <eiffel/user.h>

namespace efl::core {

    PluginHandler::PluginHandler() {}

    PluginHandler::~PluginHandler() {}

    ams::Result PluginHandler::GetPluginMeta(SlPluginMeta* out_pluginMeta, PluginName& name) {
        auto& activePluginMetas = GetInstance().m_ActivePluginMetas;
        auto foundPluginEntry = activePluginMetas.find(name.data());
        if (foundPluginEntry != activePluginMetas.end()) {
            *out_pluginMeta = foundPluginEntry->second;
        } else {
            return EFL_U_RESULT_PLUGIN_NOT_ACTIVE;
        }
        return 0;
    }

    ams::Result PluginHandler::GetPluginSharedMemInfo(SlPluginSharedMemInfo* out_sharedMemInfo, PluginName& name) {
        auto& activePluginSharedMemInfos = GetInstance().m_ActivePluginSharedMemInfos;
        auto foundPluginEntry = activePluginSharedMemInfos.find(name.data());
        if (foundPluginEntry == activePluginSharedMemInfos.end()) {
            return EFL_U_RESULT_SHARED_MEM_NOT_REGISTERED;
        }
        *out_sharedMemInfo = foundPluginEntry->second;
        activePluginSharedMemInfos.erase(foundPluginEntry);  // temp: keep it after proper cleanup impl
        return 0;
    }

}  // namespace efl::core
