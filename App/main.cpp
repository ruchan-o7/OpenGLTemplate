#include "Core/Application.h"
#include "Core/EntryPoint.h"

class ExampleLayer : public Core::Layer
{
public:
    virtual void OnUIRender() override
    {
        ImGui::Begin("Hello");
        ImGui::Button("Button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};
Core::Application *Core::CreateApplication(int argc, char **argv)
{
    Core::ApplicationSpecification spec;
    spec.Name = "Application Example";

    Core::Application *app = new Core::Application(spec);
    app->PushLayer<ExampleLayer>();
    const std::function<void()> menubar_call_back = [app]()
    {
                                if (ImGui::BeginMenu("File"))
                                {
                                    if (ImGui::MenuItem("Exit"))
                                    {
                                        app->Close();
                                    }
                                    ImGui::EndMenu();
                                } };
    app->SetMenubarCallback(menubar_call_back);
    return app;
}

//     int
//     main()
// {
//     std::cout << "Hello world! \n";
//     Core::create_window();
//     return 0;
// }