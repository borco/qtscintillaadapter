#include "scintillaedit.h"

namespace qtscintillaadapter {

ScintillaEdit::ScintillaEdit(QWidget *parent)
    : ScintillaEditBase(parent)
{
    send(SCI_SETEOLMODE, SC_EOL_LF);
    send(SCI_CONVERTEOLS, SC_EOL_LF);

    // Hide non-folding symbol margin (default width 16)
    send(SCI_SETMARGINWIDTHN, 1, 0);

    // change linenumber color
    // color is set as 0xBBGGRR
    send(SCI_STYLESETBACK, STYLE_LINENUMBER, 0xA0A0A0);

    // change the representation and color for EOL character
    // color is set as 0XAABBGGRR
    const wchar_t* nl = L"\n";
    sends(SCI_SETREPRESENTATION, reinterpret_cast<uptr_t>(nl), "↩");
    send(SCI_SETREPRESENTATIONCOLOUR, reinterpret_cast<uptr_t>(nl), 0xFFC0C0FF);
    send(SCI_SETREPRESENTATIONAPPEARANCE, reinterpret_cast<uptr_t>(nl), SC_REPRESENTATION_COLOUR);

    connect(this, &ScintillaEdit::modified, this, &ScintillaEdit::onModified);
}

ScintillaEdit::~ScintillaEdit()
{
}

bool ScintillaEdit::lineEndVisible() const
{
    return m_lineEndVisible;
}

void ScintillaEdit::setLineEndVisible(bool newLineEndVisible)
{
    if (m_lineEndVisible == newLineEndVisible)
        return;
    m_lineEndVisible = newLineEndVisible;
    emit lineEndVisibleChanged();

    send(SCI_SETVIEWEOL, newLineEndVisible);
}

bool ScintillaEdit::lineNumbersVisible() const
{
    return m_lineNumbersVisible;
}

void ScintillaEdit::setLineNumbersVisible(bool newLineNumbersVisible)
{
    if (m_lineNumbersVisible == newLineNumbersVisible)
        return;
    m_lineNumbersVisible = newLineNumbersVisible;
    emit lineNumbersVisibleChanged();

    // Set line number margin to display 2 digits
    // (Default width 0: invisible)
    send(SCI_SETMARGINWIDTHN, 0, m_lineNumbersVisible ? 20 : 0);
}

bool ScintillaEdit::lineWrapped() const
{
    return m_lineWrapped;
}

void ScintillaEdit::setLineWrapped(bool newLineWrapped)
{
    if (m_lineWrapped == newLineWrapped)
        return;
    m_lineWrapped = newLineWrapped;
    emit lineWrappedChanged();

    send(SCI_SETWRAPMODE, newLineWrapped ? SC_WRAP_WHITESPACE : SC_WRAP_NONE);
}

const QString &ScintillaEdit::text() const
{
    return m_text;
}

void ScintillaEdit::setText(const QString &txt, bool fromRawText)
{
    if (m_text == txt)
        return;

    m_text = txt;
    if (!fromRawText) {
        setRawText(m_text);
    }
    emit textChanged();
}

void ScintillaEdit::onModified(Scintilla::ModificationFlags type,
                               Scintilla::Position position,
                               Scintilla::Position length,
                               Scintilla::Position linesAdded,
                               const QByteArray &text,
                               Scintilla::Position line,
                               Scintilla::FoldLevel foldNow,
                               Scintilla::FoldLevel foldPrev)
{
    if (Scintilla::FlagSet(type, Scintilla::ModificationFlags::InsertText | Scintilla::ModificationFlags::DeleteText)) {
        auto raw_text = rawText();
        setText(raw_text, true);
    }
}

QString ScintillaEdit::rawText() const
{
    int textLength = send(SCI_GETTEXTLENGTH);
    char * buffer = new char[textLength+1];
    send(SCI_GETTEXT,textLength+1, (sptr_t)buffer);
    QString ret(buffer);
    delete [] buffer;
    return ret;
}

void ScintillaEdit::setRawText(const QString &txt)
{
    send(SCI_SETTEXT, 0, (sptr_t)txt.toUtf8().constData());
    send(SCI_SETSAVEPOINT);
    send(SCI_EMPTYUNDOBUFFER);
    send(SCI_COLOURISE, 0, -1);
}

} // qtscintillaadapter
