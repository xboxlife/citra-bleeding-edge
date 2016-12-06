// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "core/file_sys/archive_savedata.h"
#include "core/hle/kernel/process.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// FileSys namespace

namespace FileSys {

ArchiveFactory_SaveData::ArchiveFactory_SaveData(
    std::shared_ptr<ArchiveSource_SDSaveData> sd_savedata)
    : sd_savedata_source(sd_savedata) {}

ResultVal<std::unique_ptr<ArchiveBackend>> ArchiveFactory_SaveData::Open(const Path& path) {
    return sd_savedata_source->Open(Kernel::g_current_process->codeset->program_id);
}

ResultCode ArchiveFactory_SaveData::Format(const Path& path,
                                           const FileSys::ArchiveFormatInfo& format_info) {
    return sd_savedata_source->Format(Kernel::g_current_process->codeset->program_id, format_info);
}

ResultVal<ArchiveFormatInfo> ArchiveFactory_SaveData::GetFormatInfo(const Path& path) const {
    return sd_savedata_source->GetFormatInfo(Kernel::g_current_process->codeset->program_id);
}

} // namespace FileSys
