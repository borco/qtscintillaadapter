set(LIB_NAME QtScintillaAdapter)

set(LIB_SOURCES
    scintilla/include/ILexer.h
    scintilla/include/Scintilla.h
    scintilla/qt/ScintillaEditBase/PlatQt.cpp
    scintilla/qt/ScintillaEditBase/PlatQt.h
    scintilla/qt/ScintillaEditBase/ScintillaEditBase.cpp
    scintilla/qt/ScintillaEditBase/ScintillaEditBase.h
    scintilla/qt/ScintillaEditBase/ScintillaQt.cpp
    scintilla/qt/ScintillaEditBase/ScintillaQt.h
    scintilla/src/AutoComplete.cxx
    scintilla/src/AutoComplete.h
    scintilla/src/CallTip.cxx
    scintilla/src/CallTip.h
    scintilla/src/CaseConvert.cxx
    scintilla/src/CaseConvert.h
    scintilla/src/CaseFolder.cxx
    scintilla/src/CaseFolder.h
    scintilla/src/CellBuffer.cxx
    scintilla/src/CellBuffer.h
    scintilla/src/ChangeHistory.cxx
    scintilla/src/ChangeHistory.h
    scintilla/src/CharacterCategoryMap.cxx
    scintilla/src/CharacterCategoryMap.h
    scintilla/src/CharacterType.cxx
    scintilla/src/CharacterType.h
    scintilla/src/CharClassify.cxx
    scintilla/src/CharClassify.h
    scintilla/src/ContractionState.cxx
    scintilla/src/ContractionState.h
    scintilla/src/DBCS.cxx
    scintilla/src/Decoration.cxx
    scintilla/src/Decoration.h
    scintilla/src/Document.cxx
    scintilla/src/Document.h
    scintilla/src/EditModel.cxx
    scintilla/src/Editor.cxx
    scintilla/src/Editor.h
    scintilla/src/EditView.cxx
    scintilla/src/Geometry.cxx
    scintilla/src/Geometry.h
    scintilla/src/Indicator.cxx
    scintilla/src/Indicator.h
    scintilla/src/KeyMap.cxx
    scintilla/src/KeyMap.h
    scintilla/src/LineMarker.cxx
    scintilla/src/LineMarker.h
    scintilla/src/MarginView.cxx
    scintilla/src/Partitioning.h
    scintilla/src/PerLine.cxx
    scintilla/src/PerLine.h
    scintilla/src/Platform.h
    scintilla/src/PositionCache.cxx
    scintilla/src/PositionCache.h
    scintilla/src/RESearch.cxx
    scintilla/src/RESearch.h
    scintilla/src/RunStyles.cxx
    scintilla/src/RunStyles.h
    scintilla/src/ScintillaBase.cxx
    scintilla/src/ScintillaBase.h
    scintilla/src/Selection.cxx
    scintilla/src/Selection.h
    scintilla/src/SplitVector.h
    scintilla/src/Style.cxx
    scintilla/src/Style.h
    scintilla/src/UniConversion.cxx
    scintilla/src/UniConversion.h
    scintilla/src/UniqueString.cxx
    scintilla/src/ViewStyle.cxx
    scintilla/src/ViewStyle.h
    scintilla/src/XPM.cxx
    scintilla/src/XPM.h
)

qt_add_library(${LIB_NAME} STATIC
    ${LIB_SOURCES}
)

target_compile_definitions(${LIB_NAME} PUBLIC
    SCINTILLA_QT=1
    MAKING_LIBRARY=1
    _CRT_SECURE_NO_DEPRECATE=1
)

target_link_libraries(${LIB_NAME} PUBLIC
    Qt6::Core
    Qt6::Core5Compat
    Qt6::Gui
    Qt6::Widgets
)

target_include_directories(${LIB_NAME} PUBLIC
    src/
    src/scintilla/include
    src/scintilla/qt/ScintillaEditBase
    src/scintilla/src
)
