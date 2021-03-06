# file      : build/import/libodb-mssql/stub.make
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : ODB NCUEL; see accompanying LICENSE file

$(call include-once,$(scf_root)/import/libodb-mssql/configuration-rules.make,$(dcf_root))

libodb_mssql_installed :=

$(call -include,$(dcf_root)/import/libodb-mssql/configuration-dynamic.make)

ifdef libodb_mssql_installed

ifeq ($(libodb_mssql_installed),y)

$(call export,l: -lodb-mssql -lodb -lodbc,cpp-options: )

else

# Include export stub.
#
$(call include,$(scf_root)/export/libodb-mssql/stub.make)

endif

else

.NOTPARALLEL:

endif
