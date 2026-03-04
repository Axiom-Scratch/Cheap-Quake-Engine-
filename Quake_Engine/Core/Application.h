#pragma once

#if defined(_WIN32)
    #if defined(QUAKENGINE_BUILD_DLL)
        #define QUAKENGINE_API __declspec(dllexport)
    #else
        #define QUAKENGINE_API __declspec(dllimport)
    #endif
#elif defined(__linux__)
    #define QUAKENGINE_API __attribute__((visibility("default")))
#else
    #error "QuakeEngine supports only Windows and Linux."
#endif

class QUAKENGINE_API Application
{
public:
    Application() = default;
    virtual ~Application() = default;

    void Run();

protected:
    virtual void OnInit() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnShutdown();
    void Close() noexcept;

private:
    bool m_Running = true;
};