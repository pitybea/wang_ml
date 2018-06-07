//  CopyRight none@nothin.not

#include "./layer.h"

layer::layer(int input_d, int output_d) :
    input_dim(input_d), output_dim(output_d),
    parameters(new layerPara<floatType>(input_d, output_d, 1.0f / input_d)) {
}

void layer::linearFunc(vector<floatType>* result,
                       const vector<floatType>& input) {
  for (int i = 0; i < output_dim; i++) {
    (*result)[i] = parameters->b[i];
    for (int j = 0; j < input_dim; j++) {
      (*result)[i] += parameters->w[i][j] * input[j];
    }
  }
}

layer::~layer() {
  delete parameters;
}
