#include <cnoid/SimpleController>
#include <cnoid/Config>

namespace cnoid {

class CNOID_GENERAL_EXPORT DoorBreakerController : public SimpleController
{
    SimpleControllerIO* io;
    bool isToSpreadRequested;
    Link* flangeL;
    Link* flangeR;
    
public:
    static DoorBreakerController* instance();

    DoorBreakerController();
    virtual bool initialize(SimpleControllerIO* io) override;
    virtual bool control() override;
    void requestToSpread(bool on);
};

}
