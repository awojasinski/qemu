/*
 * Helper routines to provide target memory access for semihosting
 * syscalls in system emulation mode.
 *
 * Copyright (c) 2007 CodeSourcery.
 *
 * This code is licensed under the GPL
 */

#ifndef SEMIHOSTING_SOFTMMU_UACCESS_H
#define SEMIHOSTING_SOFTMMU_UACCESS_H

#include "cpu.h"

static inline uint64_t softmmu_tget64(CPUArchState *env, target_ulong addr)
{
    uint64_t val;

    cpu_memory_rw_debug(env_cpu(env), addr, (uint8_t *)&val, 8, 0);
    return tswap64(val);
}

static inline uint32_t softmmu_tget32(CPUArchState *env, target_ulong addr)
{
    uint32_t val;

    cpu_memory_rw_debug(env_cpu(env), addr, (uint8_t *)&val, 4, 0);
    return tswap32(val);
}

static inline uint32_t softmmu_tget8(CPUArchState *env, target_ulong addr)
{
    uint8_t val;

    cpu_memory_rw_debug(env_cpu(env), addr, &val, 1, 0);
    return val;
}

#define get_user_u64(arg, p) ({ arg = softmmu_tget64(env, p); 0; })
#define get_user_u32(arg, p) ({ arg = softmmu_tget32(env, p) ; 0; })
#define get_user_u8(arg, p) ({ arg = softmmu_tget8(env, p) ; 0; })
#define get_user_ual(arg, p) get_user_u32(arg, p)

static inline void softmmu_tput64(CPUArchState *env,
                                  target_ulong addr, uint64_t val)
{
    val = tswap64(val);
    cpu_memory_rw_debug(env_cpu(env), addr, (uint8_t *)&val, 8, 1);
}

static inline void softmmu_tput32(CPUArchState *env,
                                  target_ulong addr, uint32_t val)
{
    val = tswap32(val);
    cpu_memory_rw_debug(env_cpu(env), addr, (uint8_t *)&val, 4, 1);
}
#define put_user_u64(arg, p) ({ softmmu_tput64(env, p, arg) ; 0; })
#define put_user_u32(arg, p) ({ softmmu_tput32(env, p, arg) ; 0; })
#define put_user_ual(arg, p) put_user_u32(arg, p)

void *softmmu_lock_user(CPUArchState *env, target_ulong addr,
                        target_ulong len, bool copy);
#define lock_user(type, p, len, copy) softmmu_lock_user(env, p, len, copy)

char *softmmu_lock_user_string(CPUArchState *env, target_ulong addr);
#define lock_user_string(p) softmmu_lock_user_string(env, p)

void softmmu_unlock_user(CPUArchState *env, void *p,
                         target_ulong addr, target_ulong len);
#define unlock_user(s, args, len) softmmu_unlock_user(env, s, args, len)

ssize_t softmmu_strlen_user(CPUArchState *env, target_ulong addr);
#define target_strlen(p) softmmu_strlen_user(env, p)

#endif /* SEMIHOSTING_SOFTMMU_UACCESS_H */
