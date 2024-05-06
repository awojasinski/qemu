#include "qemu/osdep.h"
#include "cpu.h"
#include "gdbstub/helpers.h"
#include "qemu/host-utils.h"

#include "core-sample_controller32/core-isa.h"
#include "core-sample_controller32/core-matmap.h"
#include "overlay_tool.h"

#define xtensa_modules xtensa_modules_sample_controller32
#include "core-sample_controller32/xtensa-modules.c.inc"

static XtensaConfig sample_controller32 __attribute__((unused)) = {
    .name = "sample_controller32",
    .gdb_regmap = {
        .reg = {
#include "core-sample_controller32/gdb-config.c.inc"
        }
    },
    .isa_internal = &xtensa_modules,
    .clock_freq_khz = 40000,
    DEFAULT_SECTIONS
};

REGISTER_CORE(sample_controller32)
