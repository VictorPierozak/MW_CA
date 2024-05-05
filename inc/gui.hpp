#pragma once
#include"GenerationManager.hpp"
#include"postproc.hpp"
#include"nanogui/screen.h"
#include"nanogui/formhelper.h"
#include<unordered_map>

class GeneratorApplication: public nanogui::Screen
{ 
    public:
    GeneratorApplication(m_int dimX, m_int dimY, std::string caption);
    ~GeneratorApplication() = default;

    void mainloop();
    void shutdown();
    void run();

    private:

    std::shared_ptr<GenerationManager> _manager;
    nanogui::FormHelper* _guiHelper;
    nanogui::Window* _sideMenu;
    nanogui::Window* _imgField;
    nanogui::ImageView* _imgView;
    nanogui::Texture* _texture;
    std::unordered_map<std::string, nanogui::TextBox*> _textBoxes;

    std::string _result;

    void createSideMenu();

    void createStdTextField(std::string name);
    void loadImg();
};
