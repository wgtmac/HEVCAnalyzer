#ifndef THUMBNAILTHREAD_H_INCLUDED
#define THUMBNAILTHREAD_H_INCLUDED

#include "HEVCAnalyzer.h"
#include "HEVCodecApp.h"

class ThumbnailThread : public wxThread
{
public:
    ThumbnailThread(wxFrame* pFrame, wxImageList* pImageList, int w, int h, int bit, const wxString& path, int framenumbers=10)
    : m_sYUVPath(path), m_iSourceWidth(w), m_iSourceHeight(h), m_iYUVBit(bit), m_pImageList(pImageList), m_pFrame(pFrame),
      m_iFrameNumbers(framenumbers), m_pcPicYuvOrg(NULL)
    { }
    ~ThumbnailThread();

protected:
    virtual void* Entry();

    wxString     m_sYUVPath;
    int          m_iSourceWidth;
    int          m_iSourceHeight;
    int          m_iYUVBit;
    wxImageList* m_pImageList;
    wxFrame*     m_pFrame;

    //when the thread have processed m_iFrameNumbers frames
    //and then send message to the main thread.
    int          m_iFrameNumbers;
    TComPicYuv*  m_pcPicYuvOrg;
    TVideoIOYuv  m_cYUVIO;
};

#endif // THUMBNAILTHREAD_H_INCLUDED
