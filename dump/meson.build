system_ss.add(files('dump-hmp-cmds.c'))

specific_ss.add(when: 'CONFIG_SYSTEM_ONLY', if_true: [files('dump.c'), snappy, lzo])
specific_ss.add(when: ['CONFIG_SYSTEM_ONLY', 'TARGET_X86_64'], if_true: files('win_dump.c'))
