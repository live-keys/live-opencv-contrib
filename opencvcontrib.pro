
# --- Version Check ---

# Some linux distributions have qt version 4 already installed. Sometimes this
# can lead to running the wrong qmake version. Notify the user:

!qtVersionCheck(5, 14)::error( \
    This project requires at least Qt version 5.14. \
    Make sure you have Qt 5.14 installed and running the correct qmake. \
)

# --- Project structure ---

TEMPLATE = subdirs
SUBDIRS += contrib

## --- Subdir configurations ---
contrib.subdir = contrib

exists($$PWD/livekeys):equals(BUILD_DEPENDENCIES, true){
    SUBDIRS += livekeys
    livekeys.subdir = $$PWD/livekeys
    contrib.depends = livekeys
}

# --- Dependency configuration ---

# Include the global configuration files since otherwise they would never show
# up in your project
OTHER_FILES += \
    .qmake.conf \
    $$LIVEKEYS_DEV_PATH/project/*.pri
