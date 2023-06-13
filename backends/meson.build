system_ss.add([files(
  'cryptodev-builtin.c',
  'cryptodev.c',
  'hostmem-ram.c',
  'hostmem.c',
  'rng-builtin.c',
  'rng-egd.c',
  'rng.c',
  'confidential-guest-support.c',
), numa])

system_ss.add(when: 'CONFIG_POSIX', if_true: files('rng-random.c'))
system_ss.add(when: 'CONFIG_POSIX', if_true: files('hostmem-file.c'))
system_ss.add(when: 'CONFIG_LINUX', if_true: files('hostmem-memfd.c'))
system_ss.add(when: ['CONFIG_VHOST_USER', 'CONFIG_VIRTIO'], if_true: files('vhost-user.c'))
system_ss.add(when: 'CONFIG_VIRTIO_CRYPTO', if_true: files('cryptodev-vhost.c'))
system_ss.add(when: ['CONFIG_VIRTIO_CRYPTO', 'CONFIG_VHOST_CRYPTO'], if_true: files('cryptodev-vhost-user.c'))
system_ss.add(when: 'CONFIG_GIO', if_true: [files('dbus-vmstate.c'), gio])
system_ss.add(when: 'CONFIG_SGX', if_true: files('hostmem-epc.c'))

subdir('tpm')
