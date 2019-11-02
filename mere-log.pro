TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
        mere-log-lib     	\  # mere-log-lib
        mere-log-app     	\  # mere-log-app
#        mere-log-utils     	\  # mere-log-utils
#        mere-log-tests     	\  # mere-log-tests

#mere-log-lib.depends = mere-log-utils
mere-log-app.depends = mere-log-lib
