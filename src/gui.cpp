
#include"nanogui/common.h"
#include"nanogui/screen.h"
#include"nanogui/imageview.h"
#include"nanogui/widget.h"
#include"gui.hpp"
#include"postproc.hpp"


GeneratorApplication::GeneratorApplication(m_int dimX, m_int dimY, std::string caption):
Screen({dimX, dimY}, caption), _guiHelper(new nanogui::FormHelper(this)), _texture(nullptr)
{   
    createSideMenu();

    set_visible(true);
    perform_layout();
}

void GeneratorApplication::mainloop()
{
    nanogui::mainloop();
}

void GeneratorApplication::shutdown()
{
    nanogui::shutdown();
}

void GeneratorApplication::createStdTextField(std::string name)
{
    nanogui::TextBox* txt = new nanogui::TextBox(_sideMenu, "");
    txt->set_editable(true);
    txt->set_fixed_width(100);
    _guiHelper->add_widget(name, txt);
    _textBoxes.emplace(name, txt);
}

void GeneratorApplication::loadImg()
{
    if(_texture != nullptr) delete _texture;
    _texture = new nanogui::Texture("/home/wiktor/Desktop/MW/MW_CA/resms_0.bmp", 
    nanogui::Texture::InterpolationMode::Nearest, nanogui::Texture::InterpolationMode::Nearest);
    _imgView->set_image(_texture);
}

void GeneratorApplication::createSideMenu()
{
    _sideMenu = _guiHelper->add_window({0,0}, "Menu");
    _sideMenu->set_fixed_height(this->height());
    createStdTextField("Dimension X");
    createStdTextField("Dimension Y");
    createStdTextField("Dimension Z");
    createStdTextField("Grain number");
    createStdTextField("Iteration number");
    _guiHelper->add_button("Run", [this](){this->run();});

    _imgField = _guiHelper->add_window({0, _sideMenu->width()}, "Result");
    _imgView = new nanogui::ImageView(_imgField);
    _imgView->set_fixed_size({500,500});
    _guiHelper->add_widget("", _imgView);
}

void GeneratorApplication::run()
{
    std::cout<<"RUN\n";
    m_int dimX = std::stoi(_textBoxes.at("Dimension X")->value());
    m_int dimY = std::stoi(_textBoxes.at("Dimension Y")->value());
    m_int dimZ = std::stoi(_textBoxes.at("Dimension Z")->value());
    m_int stateNumber = std::stoi(_textBoxes.at("Grain number")->value());
    m_int itrLimit = std::stoi(_textBoxes.at("Iteration number")->value());
    _manager = std::make_shared<GenerationManager>(dimX, dimY, dimZ, itrLimit);
    _manager->setRandomUniformNucleator(stateNumber);
    _manager->setThreadsNumber(12);
    _manager->setNeighbourhood(std::shared_ptr<Neighbourhood>(new Moore));
    _manager->setBC(std::shared_ptr<BC>(new Absorption(dimX, dimY, dimZ)));
    _manager->setRule(std::shared_ptr<Rule>(new MostNumerous));
    _manager->start();
    toBmp(_manager->domain(), _manager->stateNumber(), "");
    loadImg();
}