///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 30 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PANEL_SETUP_NETCLASSES_BASE_H__
#define __PANEL_SETUP_NETCLASSES_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class WX_GRID;

#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_SETUP_NETCLASSES_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_SETUP_NETCLASSES_BASE : public wxPanel 
{
	private:
	
	protected:
		WX_GRID* m_netclassGrid;
		wxBitmapButton* m_addButton;
		wxBitmapButton* m_removeButton;
		wxTextCtrl* m_textNetFilter;
		WX_GRID* m_membershipGrid;
		wxStaticText* m_staticText24;
		WX_GRID* m_trackWidthsGrid;
		wxStaticText* m_staticText25;
		WX_GRID* m_viaSizesGrid;
		wxStaticText* m_staticText26;
		WX_GRID* m_diffPairsGrid;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSizeNetclassGrid( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnAddNetclassClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveNetclassClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSizeMembershipGrid( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		PANEL_SETUP_NETCLASSES_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~PANEL_SETUP_NETCLASSES_BASE();
	
};

#endif //__PANEL_SETUP_NETCLASSES_BASE_H__