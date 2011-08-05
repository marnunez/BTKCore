/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2011, Arnaud Barré
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __btkVTKChartXY_h
#define __btkVTKChartXY_h

#include "btkConfigure.h"

#include <vtkChartXY.h>

namespace btk
{
  class VTKChartXY : public vtkChartXY
  {
  public:
    enum {HORIZONTAL, VERTICAL, BOTH}; // Zoom mode
    
    BTK_VTK_EXPORT static VTKChartXY* New();
    vtkExportedTypeRevisionMacro(VTKChartXY, vtkChartXY, BTK_VTK_EXPORT);
    
    bool GetInteractionEnabled() const {return this->m_InteractionEnabled;};
    void SetInteractionEnabled(bool enabled) {this->m_InteractionEnabled = enabled;};
    
    int GetZoomMode() const {return this->m_ZoomMode;};
    void SetZoomMode(int mode) {this->m_ZoomMode = mode;};
    
    bool GetBoundsEnabled() {return this->m_BoundsEnabled;};
    void SetBoundsEnabled(bool enabled) {this->m_BoundsEnabled = enabled;};
    double* GetBounds() {return this->mp_Bounds;};
    void SetBounds(double xMin, double xMax, double yMin, double yMax) {double bounds[4] = {xMin, xMax, yMin, yMax}; this->SetBounds(bounds);};
    BTK_VTK_EXPORT void SetBounds(double bounds[4]);
    BTK_VTK_EXPORT void RecalculateBounds();
    
    BTK_VTK_EXPORT virtual bool MouseMoveEvent(const vtkContextMouseEvent& mouse);
    BTK_VTK_EXPORT virtual bool MouseWheelEvent(const vtkContextMouseEvent& mouse, int delta);
    
  protected:
    BTK_VTK_EXPORT VTKChartXY();
    
  private:
    VTKChartXY(const VTKChartXY& ); // Not implemented.
    void operator=(const VTKChartXY& );   // Not implemented.
    
    bool m_InteractionEnabled;
    int m_ZoomMode;
    bool m_BoundsEnabled;
    double mp_Bounds[4]; // xMin, xMax, yMin, yMax
  };
};

#endif // __btkVTKChartXY_h