typedef struct {
    Command *cmd;
    ll_node *prev;
    ll_node *next;
} ll_node;

void ll_delete(ll_node *n);
void ll_insertbefore(ll_node *before, Command *c);

ll_node *jl_head = NULL;
ll_node *jl_tail = NULL;
unsigned int jl_count = 0;

/* Job Control functions */

void jobhandler_tick(){
    ll_node *node = jl_head;

    time cyclestart = nSysTime;

    while(node != NULL){
        ll_node *t = node;
        node = node->next;
        jobstatus ret = t->cmd->update(cmd);
        if(ret & JOB_DONE){
            jobstatus done = node->cmd->stop();
            if(done & JOB_CLEANUP_COMMAND)
                free(t->cmd);
            ll_delete(t);
            --jl_count;
        }
    }

    time cycleend = nSysTime;

    time duration = cyclestart - cycleend;

    // wait for 20 msec?
    // waituntiltime(cyclestart + 20000);
}

void jobhandler_startcommand(Command *c){
    ll_insertbefore(jl_tail, c);
    c->starttime = nSysTime;
    c->start(c);
    c->data = data;
    ++jl_count;
}


void jobhandler_killall(){
    ll_node *node = jl_head;

    time cyclestart = nSysTime;

    while(node != NULL){
        ll_node *t = node;
        node = node->next;
        jobstatus done = t->cmd->stop();
        if(done & JOB_CLEANUP_COMMAND)
            free(t->cmd);
        ll_delete(t);
        --jl_count;
    }
}




/* Linked List stuff */

void ll_delete(ll_node *n){
    ll_node *prev = n->prev;
    ll_node *next = n->next;
    if(prev) prev->next = n->next;
    if(next) next->prev = n->prev;
    free(n);
}

void ll_insertbefore(ll_node *before, Command *c){
    ll_node *newnode = malloc(sizeof(ll_node));
    newnode->cmd = c;
    newnode->next = before;
    if(before) newnode->prev = before->prev;
    else newnode->prev = NULL;
    if(before->prev) before->prev->next = newnode;
    before->prev = newnode;
}
