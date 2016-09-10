/*
 * Описание определений из "sig.h"
 */

#include "sig.h"

void Sig::on() { digitalWrite(pin, level); }

void Sig::off() { digitalWrite(pin, !level); }

void Sig::inv() { digitalWrite(pin, !digitalRead(pin)); }
