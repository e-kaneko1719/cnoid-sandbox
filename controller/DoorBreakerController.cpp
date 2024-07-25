#include "DoorBreakerController.h"
#include <cnoid/EigenUtil>

using namespace std;
using namespace cnoid;

static DoorBreakerController* instance = nullptr;


DoorBreakerController* DoorBreakerController::instance()
{
    return ::instance;
}


DoorBreakerController::DoorBreakerController()
{
    ::instance = this;
}


bool DoorBreakerController::initialize(SimpleControllerIO* io)
{
    this->io = io;
    flangeL = io->body()->link("FLANGE_WEDGE_L");
//    flangeR = io->body()->link("FLANGE_WEDGE_R");

    isToSpreadRequested = false;

    if(flangeL && flangeR){
        flangeL->setActuationMode(JointDisplacement);
//        flangeR->setActuationMode(JointDisplacement);
        io->enableIO(flangeL);
//        io->enableIO(flangeR);

        return true;
    }
    return false;
}


bool DoorBreakerController::control()
{
//
//    double q_target;
//    if(isToSpreadRequested){
//        double q = std::max(flangeL->q(), flangeR->q());
//        q_target = std::min(q + radian(0.8), flangeL->q_upper());
//    } else {
//        double q = std::min(flangeL->q(), flangeR->q());
//        q_target = std::max(q - radian(0.8), 0.0);
//    }
//    flangeL->q_target() = q_target;
//    flangeR->q_target() = q_target; 
//
    return true;
}


void DoorBreakerController::requestToSpread(bool on)
{
    isToSpreadRequested = on;
}


CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(DoorBreakerController)
