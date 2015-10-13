namespace DotPHP\Base;

/**
 * DotPHP 多进程基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
abstract class MultiProcessBase extends \DotPHP\Base\ProcessBase {
    /**
     * 子进程数量。
     * 
     * @var int
     */
    private child_worker_num = 2;

    /**
     * 工作进程列表。
     * 
     * @var array
     */
    protected workers = [];

    /**
     * 初始化事件。
     * 
     * @return void
     */
    public function initialize() {}

    /**
     * 执行任务。
     * 
     * @return void
     */
    final public function execute() -> void {
        int i;
        var p, pid;

        for i in range(1, this->child_worker_num) {
            let p = new \swoole_process([this, "doTaskAction"]);
            let p->id = i;

            let pid = p->start();

            let this->workers[pid] = p;
        }

        \swoole_process::wait(true);
    }

    /**
     * 设置启动的子进程数量。
     * 
     * @param int worker_num
     * @return void
     */
    protected function setWorkerNum(int worker_num) -> void {
        if worker_num < 2 {
            throw new \DotPHP\ArgumentException("子进程数量必须大于 1。");
        }

        let this->child_worker_num = worker_num;
    }

    /**
     * 子进程启动后触发此事件。
     * 
     * @param \swoole_process worker
     * @return void
     */
    abstract public function doTaskAction(<\swoole_process> worker) -> void;
}