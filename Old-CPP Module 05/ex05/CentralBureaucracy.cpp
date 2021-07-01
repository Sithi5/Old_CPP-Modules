
#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() : _blocks(new OfficeBlock[20]) {
    for (int i = 0; i < 20; ++i) {
        this->_blocks[i].setIntern(new Intern());
    }
    this->_tasks = NULL;
}

OfficeBlock *CentralBureaucracy::getBlocks() const {
    return this->_blocks;
}

const char *CentralBureaucracy::OfficeDoesntExist::what() const throw() {
    return "Office block doesn't exist. Office blocks are between 0 and 19.";
}

OfficeBlock CentralBureaucracy::getBlockNb(int n) const {
    if (n > 19 || n < 0) {
        throw CentralBureaucracy::OfficeDoesntExist();
    }
    return this->_blocks[n];
}

void CentralBureaucracy::setBlocks(OfficeBlock *blocks) {
    this->_blocks = blocks;
}

void CentralBureaucracy::queueUp(std::string const &task, std::string const &target) {
    if (!task.empty()) {
        if (this->_tasks) {
            t_list *root = this->_tasks;
            t_list *new_task = new t_list;
            new_task->next = NULL;
            new_task->task = task;
            new_task->target = target;

            while (this->_tasks->next) {
                this->_tasks = this->_tasks->next;
            }
            this->_tasks->next = new_task;
            this->_tasks = root;
            return;
        } else {
            this->_tasks = new t_list;
            this->_tasks->next = NULL;
            this->_tasks->task = task;
            this->_tasks->target = target;
            return;
        }
    }
    std::cout << "Cannot add an empty task." << std::endl;
}

void CentralBureaucracy::executeTask(t_list *task, OfficeBlock block) {
    try{
        block.doBureaucracy(task->task, task->target);
    }
    catch(std::exception const &e){
        std::cerr << "The task : \"" << task->task << "\" failed in one of the block : " << e.what() << std::endl;
    }
}

void CentralBureaucracy::executeAllTask() {
    int i = 0;
    OfficeBlock *blocks = this->getBlocks();
    while (this->_tasks) {
        t_list *last = this->_tasks;
        this->executeTask(this->_tasks, blocks[i]);
        this->_tasks = this->_tasks->next;
        delete last;
        i++;
        std::cout <<std::endl;
        if (i > 19){
            i = 0;
        }
    }
    this->_tasks = NULL;
}

void CentralBureaucracy::hiring(Bureaucrat *jobless) {
    OfficeBlock *blocks = this->getBlocks();
    for (int i = 0; i < 20; i++) {
        if (!blocks[i].getFirstBureaucrat()) {
            blocks[i].setFirstBureaucrat(jobless);
            std::cout << "The jobless "<< jobless->getName() << " bureaucrat has been accepted as first bureaucrat in office number : " << i
                      << std::endl;
            return;
        } else if (!blocks[i].getSecondBureaucrat()) {
            blocks[i].setSecondBureaucrat(jobless);
            std::cout << "The jobless " << jobless->getName() << " bureaucrat has been accepted as second bureaucrat in office number : " << i
                      << std::endl;
            return;
        }
    }
    std::cout << "Central office is full ! the jobless "<< jobless->getName() <<  " bureaucrat has been refused." << std::endl;
    delete jobless;

}

CentralBureaucracy::~CentralBureaucracy() {
    OfficeBlock *blocks = this->getBlocks();
    for (int i = 0; i < 20; i++) {
        delete blocks[i].getIntern();
        if (blocks[i].getFirstBureaucrat()) {
            delete blocks[i].getFirstBureaucrat();
        }
        if (blocks[i].getSecondBureaucrat()) {
            delete blocks[i].getSecondBureaucrat();
        }
    }
}