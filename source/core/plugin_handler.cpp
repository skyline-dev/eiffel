#include "plugin_handler.hpp"

#include <eiffel/user.h>

namespace efl::core {

    PluginHandler::PluginHandler() {}

    PluginHandler::~PluginHandler() {}

    ams::Result PluginHandler::GetPluginMeta(SlPluginMeta* out_pluginMeta, std::string_view name) {
        auto& records = GetInstance().m_ActivePluginMetas;
        auto foundPluginEntry = records.find(name);
        if (foundPluginEntry != records.end()) {
            *out_pluginMeta = foundPluginEntry->second;
        } else {
            return EFL_U_RESULT_PLUGIN_NOT_ACTIVE;
        }
        return 0;
    }

    ams::Result PluginHandler::GetPluginSharedMemInfo(SharedMemory* out_sharedMem, std::string_view name) {
        auto& records = GetInstance().m_ActivePluginSharedMems;
        auto foundPluginEntry = records.find(name);
        if (foundPluginEntry != records.end()) {
            *out_sharedMem = foundPluginEntry->second;
        } else {
            return EFL_U_RESULT_SHARED_MEM_NOT_REGISTERED;
        }
        return 0;
    }

}  // namespace efl::core
