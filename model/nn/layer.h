//  CopyRight none@nothing.not
#ifndef MODEL_NN_LAYER_H_
#define MODEL_NN_LAYER_H_

#include <vector>

#include "../../types.h"

using std::vector;

template<class T>
struct layerPara {
  vector<vector<T>> w;
  vector<T> b;
  layerPara(int input_d, int output_d, T val) :
    w(vector<vector<T>>(output_d, vector<T>(input_d, val))),
    b(vector<T>(output_d, val)) {}
};

class layer {
 public:
  layer(int, int);
  void linearFunc(vector<floatType>*,
                  const vector<floatType>&);
  ~layer();
  
 private:
  int input_dim;
  int output_dim;
  layerPara<floatType>* parameters;
  
};

#endif  // MODEL_NN_LAYER_H_
