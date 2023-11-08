#include <iostream>
#include <vector>

class Node {
public:
    /**
     * @param data - Data of any type.
     * @param id - The id of this node.
     */
    Node(int data, int id) : data(data), id(id) {}

    int data;
    int id;
};

class Layer {
public:
    /**
     * @param nodes - All of the nodes in the layer.
     * @param inputs - The inputs of this node.
     * @param outputs - The outputs of this node.
     */
    Layer(std::vector<Node> nodes, std::vector<std::vector<int>> inputs = {}, std::vector<int> outputs = {})
        : nodes(nodes), inputs(inputs), outputs(outputs) {}

    std::vector<Node> nodes;
    std::vector<std::vector<int>> inputs;
    std::vector<int> outputs;
};

class NeuralNetwork {
public:
    /**
     * @param inputLayer - The input layer of this neural network.
     * @param hiddenLayers - The hidden layers of this network.
     * @param outputLayer - The output layers of the network.
     */
    NeuralNetwork(Layer inputLayer, std::vector<Layer> hiddenLayers, Layer outputLayer)
        : inputLayer(inputLayer), hiddenLayers(hiddenLayers), outputLayer(outputLayer) {}

    Layer inputLayer;
    std::vector<Layer> hiddenLayers;
    Layer outputLayer;
};

/**
 * @param network - The network to be calculated.
 * @returns - The output layer that it returns.
 */
Layer calculateNetwork(NeuralNetwork network) {
    NeuralNetwork currNet = network;
    for (size_t hiddenLayer = 0; hiddenLayer < currNet.hiddenLayers.size(); hiddenLayer++) {
        Layer currLayer = currNet.hiddenLayers[hiddenLayer];
        std::cout << "Current Layer: ";
        for (size_t node = 0; node < currLayer.nodes.size(); node++) {
            std::cout << "Current Node: ";
            currNet.hiddenLayers[hiddenLayer].nodes[node].data = currNet.hiddenLayers[hiddenLayer].inputs;
        }
    }
    return currNet.outputLayer;
}

int main() {
    // Create a test network
    Layer inputLayer({Node(3, 0), Node(1, 1)}, {}, {2, 3, 4});
    std::vector<Layer> hiddenLayers = {Layer({Node(0, 2), Node(0, 3), Node(0, 4)}, {{0, 1}, {0}}, {5, 6, -1})};
    Layer outputLayer({Node(0, 5), Node(0, 6)}, {1}, {});
    NeuralNetwork net(inputLayer, hiddenLayers, outputLayer);

    calculateNetwork(net);

    return 0;
}