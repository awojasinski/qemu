qmp_ss.add(files('monitor.c', 'qmp.c', 'qmp-cmds-control.c'))

system_ss.add(files(
  'hmp-cmds.c',
  'hmp.c',
))
system_ss.add([spice_headers, files('qmp-cmds.c')])

specific_ss.add(when: 'CONFIG_SYSTEM_ONLY', if_true: [files('misc.c'), spice])
