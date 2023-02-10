#pragma once

#include <ScintillaEditBase.h>

namespace qtscintillaadapter {

class ScintillaEdit: public ScintillaEditBase
{
    Q_OBJECT

    Q_PROPERTY(bool lineEndVisible READ lineEndVisible WRITE setLineEndVisible NOTIFY lineEndVisibleChanged)
    Q_PROPERTY(bool lineNumbersVisible READ lineNumbersVisible WRITE setLineNumbersVisible NOTIFY lineNumbersVisibleChanged)
    Q_PROPERTY(bool lineWrapped READ lineWrapped WRITE setLineWrapped NOTIFY lineWrappedChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit ScintillaEdit(QWidget *parent = 0);
    virtual ~ScintillaEdit();

    bool lineEndVisible() const;
    void setLineEndVisible(bool newLineEndVisible);

    bool lineNumbersVisible() const;
    void setLineNumbersVisible(bool newLineNumbersVisible);

    bool lineWrapped() const;
    void setLineWrapped(bool newLineWrapped);

    const QString &text() const;
    void setText(const QString &newText, bool fromRawText=false);

signals:
    void lineEndVisibleChanged();
    void lineNumbersVisibleChanged();
    void lineWrappedChanged();
    void textChanged();

protected:
    void onModified(Scintilla::ModificationFlags type,
                    Scintilla::Position position,
                    Scintilla::Position length,
                    Scintilla::Position linesAdded,
                    const QByteArray &text,
                    Scintilla::Position line,
                    Scintilla::FoldLevel foldNow,
                    Scintilla::FoldLevel foldPrev);
    QString rawText() const;
    void setRawText(const QString& txt);

    bool m_lineEndVisible = false;
    bool m_lineNumbersVisible = false;
    bool m_lineWrapped = false;

    QString m_text;
};

} // qtscintillaadapter
