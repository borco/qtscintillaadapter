set(LIB_NAME QtScintillaAdapter)

set(LIB_SOURCES
    src/qtscintillaadapter/scintillaedit.cpp
    src/qtscintillaadapter/scintillaedit.h
    src/scintilla/include/ILexer.h
    src/scintilla/include/Scintilla.h
    src/scintilla/qt/ScintillaEditBase/PlatQt.cpp
    src/scintilla/qt/ScintillaEditBase/PlatQt.h
    src/scintilla/qt/ScintillaEditBase/ScintillaEditBase.cpp
    src/scintilla/qt/ScintillaEditBase/ScintillaEditBase.h
    src/scintilla/qt/ScintillaEditBase/ScintillaQt.cpp
    src/scintilla/qt/ScintillaEditBase/ScintillaQt.h
    src/scintilla/src/AutoComplete.cxx
    src/scintilla/src/AutoComplete.h
    src/scintilla/src/CallTip.cxx
    src/scintilla/src/CallTip.h
    src/scintilla/src/CaseConvert.cxx
    src/scintilla/src/CaseConvert.h
    src/scintilla/src/CaseFolder.cxx
    src/scintilla/src/CaseFolder.h
    src/scintilla/src/CellBuffer.cxx
    src/scintilla/src/CellBuffer.h
    src/scintilla/src/ChangeHistory.cxx
    src/scintilla/src/ChangeHistory.h
    src/scintilla/src/CharacterCategoryMap.cxx
    src/scintilla/src/CharacterCategoryMap.h
    src/scintilla/src/CharacterType.cxx
    src/scintilla/src/CharacterType.h
    src/scintilla/src/CharClassify.cxx
    src/scintilla/src/CharClassify.h
    src/scintilla/src/ContractionState.cxx
    src/scintilla/src/ContractionState.h
    src/scintilla/src/DBCS.cxx
    src/scintilla/src/Decoration.cxx
    src/scintilla/src/Decoration.h
    src/scintilla/src/Document.cxx
    src/scintilla/src/Document.h
    src/scintilla/src/EditModel.cxx
    src/scintilla/src/Editor.cxx
    src/scintilla/src/Editor.h
    src/scintilla/src/EditView.cxx
    src/scintilla/src/Geometry.cxx
    src/scintilla/src/Geometry.h
    src/scintilla/src/Indicator.cxx
    src/scintilla/src/Indicator.h
    src/scintilla/src/KeyMap.cxx
    src/scintilla/src/KeyMap.h
    src/scintilla/src/LineMarker.cxx
    src/scintilla/src/LineMarker.h
    src/scintilla/src/MarginView.cxx
    src/scintilla/src/Partitioning.h
    src/scintilla/src/PerLine.cxx
    src/scintilla/src/PerLine.h
    src/scintilla/src/Platform.h
    src/scintilla/src/PositionCache.cxx
    src/scintilla/src/PositionCache.h
    src/scintilla/src/RESearch.cxx
    src/scintilla/src/RESearch.h
    src/scintilla/src/RunStyles.cxx
    src/scintilla/src/RunStyles.h
    src/scintilla/src/ScintillaBase.cxx
    src/scintilla/src/ScintillaBase.h
    src/scintilla/src/Selection.cxx
    src/scintilla/src/Selection.h
    src/scintilla/src/SplitVector.h
    src/scintilla/src/Style.cxx
    src/scintilla/src/Style.h
    src/scintilla/src/UniConversion.cxx
    src/scintilla/src/UniConversion.h
    src/scintilla/src/UniqueString.cxx
    src/scintilla/src/ViewStyle.cxx
    src/scintilla/src/ViewStyle.h
    src/scintilla/src/XPM.cxx
    src/scintilla/src/XPM.h
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
