#freetype

THIRDPARTY_PRODUCT("FREETYPE" "freetype2/ft2build.h" "CSF_FREETYPE" "")

list (REMOVE_ITEM 3RDPARTY_INCLUDE_DIRS "${3RDPARTY_FREETYPE_INCLUDE_DIR}")
list (APPEND 3RDPARTY_INCLUDE_DIRS "${3RDPARTY_FREETYPE_INCLUDE_DIR}/freetype2")
