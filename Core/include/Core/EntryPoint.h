#ifndef _ENTRY_POINT_H
#define _ENTRY_POINT_H
extern Core::Application *Core::CreateApplication(int argc, char **argv);
bool g_ApplicationRunning = true;

namespace Core
{
    int Main(int argc, char **argv)
    {
        while (g_ApplicationRunning)
        {
            Core::Application *app = Core::CreateApplication(argc, argv);
            app->Run();
            delete app;
        }
        return 0;
    }
} // namespace Core
int main(int argc, char **argv)
{
    return Core::Main(argc, argv);
}
#endif // _ENTRY_POINT_H