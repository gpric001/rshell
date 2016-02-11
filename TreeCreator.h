#ifndef TREECREATOR_H
#define TREECREATOR_H

#typedef std::vector<std::vector<std::string > > tokens; 
class TreeCreator{
    public:
        TreeCreator();
        CommandComponent* create();
    private:
        CommandComponent* build(int start, tokens& input);
        CommandComponent* buildSub(int start, int end, tokens& input);
        CommandComponent* buildConnector(std::string token,
                                         CommandComponent* left,
                                         CommandComponent* right);
        CommandComponent* buildCmd(tokens input);
}
#endif
