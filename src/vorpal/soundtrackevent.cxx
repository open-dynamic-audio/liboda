
#include <vorpal/soundtrackevent.h>

namespace vorpal {

namespace {
using std::shared_ptr;
using std::string;
using std::vector;
} // unnamed namespace

SoundtrackEvent::SoundtrackEvent(const shared_ptr<DSPUnit> &dspunit,
                                 const shared_ptr<AudioUnit> &audiounit)
  : dspunit_(dspunit), audiounit_(audiounit) {}

void SoundtrackEvent::processAudio() {
  dspunit_->transferSignal(audiounit_);
}

void SoundtrackEvent::setAudioSource(float x, float y, float z) {
  audiounit_->setPosition(x, y, z);
}

void SoundtrackEvent::pushCommand(const string &identifier,
                                  const vector<Parameter> &parameters) {
  dspunit_->pushCommand(identifier, parameters);
}

} // namespace vorpal

