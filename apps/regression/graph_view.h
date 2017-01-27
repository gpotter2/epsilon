#ifndef REGRESSION_GRAPH_VIEW_H
#define REGRESSION_GRAPH_VIEW_H

#include <escher.h>
#include "store.h"
#include "../constant.h"
#include "../curve_view.h"

namespace Regression {

class GraphView : public CurveView {
public:
  GraphView(Store * store, CurveViewCursor * cursor, ::BannerView * bannerView, View * cursorView);
  void drawRect(KDContext * ctx, KDRect rect) const override;
private:
  constexpr static KDCoordinate k_dotSize = 5;
  char * label(Axis axis, int index) const override;
  float evaluateModelWithParameter(Model * curve, float t) const override;
  Store * m_store;
  char m_xLabels[k_maxNumberOfXLabels][Float::bufferSizeForFloatsWithPrecision(Constant::ShortNumberOfSignificantDigits)];
  char m_yLabels[k_maxNumberOfYLabels][Float::bufferSizeForFloatsWithPrecision(Constant::ShortNumberOfSignificantDigits)];
};

}


#endif