/*
 *  Copyright © 2017-2020 Wellington Wallace
 *
 *  This file is part of PulseEffects.
 *
 *  PulseEffects is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PulseEffects is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with PulseEffects.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef AUTOGAIN_HPP
#define AUTOGAIN_HPP

#include "plugin_base.hpp"

class AutoGain : public PluginBase {
 public:
  AutoGain(const std::string& tag, const std::string& schema, const std::string& schema_path);
  AutoGain(const AutoGain&) = delete;
  auto operator=(const AutoGain&) -> AutoGain& = delete;
  AutoGain(const AutoGain&&) = delete;
  auto operator=(const AutoGain &&) -> AutoGain& = delete;
  ~AutoGain() override;

  GstElement* autogain = nullptr;

  sigc::signal<void, float> momentary, shortterm, integrated, relative, loudness, range, gain;

 private:
  void bind_to_gsettings();
};

#endif
