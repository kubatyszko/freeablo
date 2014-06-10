#include "guimanager.h"

#include "../farender/renderer.h"

namespace FAGui
{
    void GuiManager::destroy()
    {
        for(size_t i = 0; i < mDocs.size(); i++)
            remove(mDocs[i]);
    }

    void GuiManager::update()
    {
        FARender::Renderer* renderer = FARender::Renderer::get();

        renderer->lockGui();
        renderer->getRocketContext()->Update();
        renderer->unlockGui();
    }
    
    void GuiManager::display(const std::string& path)
    {
        FARender::Renderer* renderer = FARender::Renderer::get();
        Rocket::Core::ElementDocument* doc = renderer->getRocketContext()->LoadDocument(path.c_str());
        
        renderer->lockGui();
        doc->Show();
        renderer->unlockGui();

        mDocs.push_back(doc);
    }
    
    void GuiManager::showGameBottomMenu()
    {
        display("resources/gui/bottommenu.rml");
    }
    
    void GuiManager::remove(Rocket::Core::ElementDocument* doc)
    {
        doc->RemoveReference();
        doc->Close();
    }
}
