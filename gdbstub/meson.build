#
# The main gdbstub still relies on per-build definitions of various
# types. The bits pushed to softmmu/user.c try to use guest agnostic
# types such as hwaddr.
#

specific_ss.add(files('gdbstub.c'))

# These have to built to the target ABI
specific_ss.add(files('syscalls.c'))

system_ss.add(files('softmmu.c'))
user_ss.add(files('user.c'))
