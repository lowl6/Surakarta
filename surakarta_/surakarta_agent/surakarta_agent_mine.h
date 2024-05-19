#include <memory>
#include "../surakarta/surakarta_common.h"
#include "../surakarta/surakarta_rule_manager.h"
#include "../surakarta/global_random_generator.h"
class SurakartaAgentMine {
   public:
    SurakartaAgentMine(std::shared_ptr<SurakartaBoard> board,
                       std::shared_ptr<SurakartaGameInfo> game_info,
                       std::shared_ptr<SurakartaRuleManager> rule_manager)
        : board_size_(board->boardSize),
        board_(std::const_pointer_cast<const SurakartaBoard>(board)),
        game_info_(std::const_pointer_cast<const SurakartaGameInfo>(game_info)),
        rule_manager_(rule_manager) {}

   SurakartaMove CalculateMove() ;
   protected:
       unsigned int board_size_;
       std::shared_ptr<const SurakartaBoard> board_;
       std::shared_ptr<const SurakartaGameInfo> game_info_;
       std::shared_ptr<SurakartaRuleManager> rule_manager_;
};
