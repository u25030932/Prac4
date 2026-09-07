<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TaskForge - Film Production Management System</title>
    <style>
        /* Reset and Base Styles */
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            line-height: 1.6;
            color: #333;
            background: #f4f7fa;
            padding: 20px;
        }
        
        .container {
            max-width: 1200px;
            margin: 0 auto;
            background: white;
            padding: 40px;
            border-radius: 12px;
            box-shadow: 0 8px 24px rgba(0,0,0,0.1);
        }
        
        /* Header */
        .header {
            text-align: center;
            padding-bottom: 30px;
            border-bottom: 3px solid #2c3e50;
            margin-bottom: 30px;
        }
        
        .header h1 {
            font-size: 2.8em;
            color: #2c3e50;
            margin-bottom: 10px;
            font-weight: 700;
        }
        
        .header .subtitle {
            font-size: 1.2em;
            color: #7f8c8d;
            font-weight: 300;
        }
        
        .badge {
            display: inline-block;
            padding: 5px 15px;
            background: #3498db;
            color: white;
            border-radius: 20px;
            font-size: 0.9em;
            margin: 5px;
        }
        
        /* Sections */
        .section {
            margin-bottom: 40px;
            padding: 25px;
            background: #f8f9fa;
            border-radius: 8px;
            border-left: 4px solid #3498db;
        }
        
        .section h2 {
            color: #2c3e50;
            font-size: 1.8em;
            margin-bottom: 15px;
            display: flex;
            align-items: center;
            gap: 10px;
        }
        
        .section h2 .icon {
            font-size: 1.2em;
        }
        
        .section h3 {
            color: #34495e;
            font-size: 1.3em;
            margin-top: 20px;
            margin-bottom: 10px;
        }
        
        .section p {
            margin-bottom: 12px;
            color: #555;
        }
        
        /* Code Blocks */
        .code-block {
            background: #2d2d2d;
            color: #f8f8f2;
            padding: 20px;
            border-radius: 8px;
            font-family: 'Courier New', monospace;
            font-size: 0.95em;
            overflow-x: auto;
            margin: 15px 0;
            position: relative;
        }
        
        .code-block .comment {
            color: #6a9955;
        }
        
        .code-block .keyword {
            color: #c586c0;
        }
        
        .code-block .string {
            color: #ce9178;
        }
        
        .code-block .function {
            color: #dcdcaa;
        }
        
        .code-block .number {
            color: #b5cea8;
        }
        
        /* Lists */
        .feature-list {
            list-style: none;
            padding: 0;
        }
        
        .feature-list li {
            padding: 10px 15px;
            margin-bottom: 8px;
            background: white;
            border-radius: 6px;
            border-left: 3px solid #3498db;
            box-shadow: 0 1px 3px rgba(0,0,0,0.1);
        }
        
        .feature-list li strong {
            color: #2c3e50;
        }
        
        /* Grid */
        .grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            margin: 20px 0;
        }
        
        .grid-item {
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 8px rgba(0,0,0,0.1);
            text-align: center;
        }
        
        .grid-item .emoji {
            font-size: 2.5em;
            margin-bottom: 10px;
        }
        
        .grid-item h4 {
            color: #2c3e50;
            margin-bottom: 5px;
        }
        
        .grid-item p {
            color: #7f8c8d;
            font-size: 0.95em;
        }
        
        /* Tables */
        .table-wrapper {
            overflow-x: auto;
            margin: 15px 0;
        }
        
        table {
            width: 100%;
            border-collapse: collapse;
            background: white;
        }
        
        table th {
            background: #2c3e50;
            color: white;
            padding: 12px 15px;
            text-align: left;
            font-weight: 600;
        }
        
        table td {
            padding: 10px 15px;
            border-bottom: 1px solid #ecf0f1;
        }
        
        table tr:hover {
            background: #f8f9fa;
        }
        
        /* Commands */
        .command-box {
            background: #1e1e1e;
            color: #d4d4d4;
            padding: 15px 20px;
            border-radius: 6px;
            font-family: 'Courier New', monospace;
            margin: 10px 0;
            border-left: 4px solid #3498db;
        }
        
        .command-box .prompt {
            color: #4ec9b0;
        }
        
        /* Buttons */
        .btn {
            display: inline-block;
            padding: 10px 25px;
            background: #3498db;
            color: white;
            text-decoration: none;
            border-radius: 6px;
            font-weight: 600;
            transition: background 0.3s;
            margin: 5px;
        }
        
        .btn:hover {
            background: #2980b9;
        }
        
        .btn-success {
            background: #27ae60;
        }
        
        .btn-success:hover {
            background: #229954;
        }
        
        .btn-warning {
            background: #f39c12;
        }
        
        .btn-warning:hover {
            background: #d68910;
        }
        
        /* Pattern Tags */
        .pattern-tag {
            display: inline-block;
            padding: 3px 12px;
            border-radius: 15px;
            font-size: 0.8em;
            font-weight: 600;
            margin: 2px;
        }
        
        .tag-composite { background: #e74c3c; color: white; }
        .tag-state { background: #2ecc71; color: white; }
        .tag-decorator { background: #f39c12; color: white; }
        .tag-iterator { background: #9b59b6; color: white; }
        
        /* Footer */
        .footer {
            margin-top: 40px;
            padding-top: 20px;
            border-top: 2px solid #ecf0f1;
            text-align: center;
            color: #7f8c8d;
            font-size: 0.95em;
        }
        
        /* Responsive */
        @media (max-width: 768px) {
            .container {
                padding: 20px;
            }
            
            .header h1 {
                font-size: 2em;
            }
            
            .section {
                padding: 15px;
            }
            
            .grid {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <!-- Header -->
        <div class="header">
            <h1>⚡ TaskForge</h1>
            <div class="subtitle">Hierarchical Work Processing System for Film Production</div>
            <div style="margin-top: 15px;">
                <span class="badge">Composite</span>
                <span class="badge">State</span>
                <span class="badge">Decorator</span>
                <span class="badge">Iterator</span>
                <span class="badge">C++11</span>
            </div>
        </div>

        <!-- Quick Navigation -->
        <div style="background: #ecf0f1; padding: 15px; border-radius: 8px; margin-bottom: 30px;">
            <strong>📌 Quick Navigation:</strong>
            <a href="#overview">Overview</a> |
            <a href="#patterns">Patterns</a> |
            <a href="#build">Build & Run</a> |
            <a href="#commands">Commands</a> |
            <a href="#structure">Structure</a> |
            <a href="#features">Features</a> |
            <a href="#debugging">Debugging</a>
        </div>

        <!-- Overview -->
        <section class="section" id="overview">
            <h2><span class="icon">📋</span> Overview</h2>
            <p>
                <strong>TaskForge</strong> is a work-processing system designed for film production pipelines. 
                It manages hierarchical tasks where groups can contain both individual tasks and nested groups, 
                allowing for complex production workflows to be modelled and executed.
            </p>
            
            <div class="grid">
                <div class="grid-item">
                    <div class="emoji">🎬</div>
                    <h4>Domain</h4>
                    <p>Film Production Pipeline</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">🏗️</div>
                    <h4>Architecture</h4>
                    <p>Composite + State + Decorator + Iterator</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">🔧</div>
                    <h4>Language</h4>
                    <p>C++11 with STL</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">🐳</div>
                    <h4>Environment</h4>
                    <p>Docker + GDB + Valgrind</p>
                </div>
            </div>
        </section>

        <!-- Patterns -->
        <section class="section" id="patterns">
            <h2><span class="icon">🎯</span> GoF Pattern Implementation</h2>
            
            <h3>🏗️ Composite Pattern</h3>
            <ul class="feature-list">
                <li><strong>Component:</strong> <code>ToDoItem</code> - Abstract base class</li>
                <li><strong>Leaf:</strong> <code>ToDoTask</code> - Individual work item</li>
                <li><strong>Composite:</strong> <code>ProductionGroup</code> - Container for tasks and groups</li>
            </ul>

            <h3>🔄 State Pattern</h3>
            <ul class="feature-list">
                <li><strong>Context:</strong> <code>ToDoTask</code> - Maintains current state</li>
                <li><strong>State Interface:</strong> <code>State</code> - Abstract base</li>
                <li><strong>Concrete States:</strong> <code>Planning</code>, <code>Progressing</code>, <code>Paused</code>, <code>Cancelled</code>, <code>Finished</code></li>
            </ul>

            <h3>🎨 Decorator Pattern</h3>
            <ul class="feature-list">
                <li><strong>Component:</strong> <code>ToDoItem</code> - Wrapped interface</li>
                <li><strong>Decorator:</strong> <code>TaskDecorator</code> - Abstract decorator</li>
                <li><strong>Concrete Decorators:</strong> <code>PriorityDecorator</code>, <code>CostAdjustmentDecorator</code></li>
            </ul>

            <h3>📊 Iterator Pattern</h3>
            <ul class="feature-list">
                <li><strong>Iterator Interface:</strong> <code>ItemIterator</code> - Abstract iterator</li>
                <li><strong>Concrete Iterators:</strong> <code>StandardTraversalIterator</code>, <code>EstimatedCostIterator</code></li>
                <li><strong>Aggregate:</strong> <code>ToDoItem</code> - Provides iterator factory method</li>
            </ul>
        </section>

        <!-- Build & Run -->
        <section class="section" id="build">
            <h2><span class="icon">🚀</span> Build & Run</h2>
            
            <h3>📦 Docker Setup</h3>
            <div class="command-box">
                <span class="prompt">$</span> docker build -t taskforge .<br>
                <span class="prompt">$</span> docker run --rm -it taskforge
            </div>

            <h3>🔧 Local Build</h3>
            <div class="command-box">
                <span class="prompt">$</span> make<br>
                <span class="prompt">$</span> ./taskforge
            </div>

            <h3>🧹 Clean Build</h3>
            <div class="command-box">
                <span class="prompt">$</span> make clean<br>
                <span class="prompt">$</span> make
            </div>
        </section>

        <!-- Commands -->
        <section class="section" id="commands">
            <h2><span class="icon">🛠️</span> Useful Commands</h2>
            
            <div class="table-wrapper">
                <table>
                    <thead>
                        <tr>
                            <th>Command</th>
                            <th>Description</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr>
                            <td><code>make</code></td>
                            <td>Compile the project</td>
                        </tr>
                        <tr>
                            <td><code>make clean</code></td>
                            <td>Remove object files and executable</td>
                        </tr>
                        <tr>
                            <td><code>./taskforge</code></td>
                            <td>Run the program</td>
                        </tr>
                        <tr>
                            <td><code>gdb ./taskforge</code></td>
                            <td>Debug with GDB</td>
                        </tr>
                        <tr>
                            <td><code>valgrind --leak-check=full ./taskforge</code></td>
                            <td>Memory leak check</td>
                        </tr>
                        <tr>
                            <td><code>docker build -t taskforge .</code></td>
                            <td>Build Docker image</td>
                        </tr>
                        <tr>
                            <td><code>docker run --rm -it taskforge</code></td>
                            <td>Run in Docker container</td>
                        </tr>
                    </tbody>
                </table>
            </div>
        </section>

        <!-- Project Structure -->
        <section class="section" id="structure">
            <h2><span class="icon">📁</span> Project Structure</h2>
            
            <div class="code-block">
                TaskForge/<br>
                ├── src/<br>
                │   ├── headers/<br>
                │   │   ├── ToDoItem.h<br>
                │   │   ├── ItemIterator.h<br>
                │   │   ├── ToDoTask.h<br>
                │   │   ├── ProductionGroup.h<br>
                │   │   ├── State.h<br>
                │   │   ├── TaskDecorator.h<br>
                │   │   ├── PriorityDecorator.h<br>
                │   │   └── CostAdjustmentDecorator.h<br>
                │   ├── source/<br>
                │   │   ├── ToDoItem.cpp<br>
                │   │   ├── ToDoTask.cpp<br>
                │   │   ├── ProductionGroup.cpp<br>
                │   │   ├── State.cpp<br>
                │   │   ├── TaskDecorator.cpp<br>
                │   │   ├── PriorityDecorator.cpp<br>
                │   │   ├── CostAdjustmentDecorator.cpp<br>
                │   │   └── main.cpp<br>
                │   └── iterators/<br>
                │       ├── StandardTraversalIterator.h<br>
                │       ├── StandardTraversalIterator.cpp<br>
                │       ├── EstimatedCostIterator.h<br>
                │       └── EstimatedCostIterator.cpp<br>
                ├── docs/<br>
                │   ├── UML_Class_Diagram.png<br>
                │   ├── UML_Object_Diagram.png<br>
                │   ├── UML_State_Diagram.png<br>
                │   ├── Activity_Diagram_1.png<br>
                │   ├── Activity_Diagram_2.png<br>
                │   └── Activity_Diagram_3.png<br>
                ├── Dockerfile<br>
                ├── Makefile<br>
                ├── README.md<br>
                └── .gitignore<br>
            </div>
        </section>

        <!-- Features -->
        <section class="section" id="features">
            <h2><span class="icon">✨</span> Key Features</h2>
            
            <div class="grid">
                <div class="grid-item">
                    <div class="emoji">🌳</div>
                    <h4>Nested Hierarchy</h4>
                    <p>Support for 3+ levels of nesting with groups and tasks</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">🔄</div>
                    <h4>State Management</h4>
                    <p>5 lifecycle states with valid/invalid transitions</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">🎨</div>
                    <h4>Runtime Decoration</h4>
                    <p>Stackable priority and cost adjustments</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">📊</div>
                    <h4>Multiple Traversals</h4>
                    <p>Standard and cost-based iteration</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">🔍</div>
                    <h4>Memory Safety</h4>
                    <p>Valgrind verified, no memory leaks</p>
                </div>
                <div class="grid-item">
                    <div class="emoji">🐳</div>
                    <h4>Containerized</h4>
                    <p>Runs in Docker with all dependencies</p>
                </div>
            </div>
        </section>

        <!-- Debugging -->
        <section class="section" id="debugging">
            <h2><span class="icon">🐛</span> Debugging & Memory Analysis</h2>
            
            <h3>GDB Debugging</h3>
            <div class="command-box">
                <span class="prompt">$</span> gdb ./taskforge<br>
                <span class="prompt">(gdb)</span> break main.cpp:42<br>
                <span class="prompt">(gdb)</span> run<br>
                <span class="prompt">(gdb)</span> info locals<br>
                <span class="prompt">(gdb)</span> print item->getDescription()<br>
                <span class="prompt">(gdb)</span> continue<br>
            </div>

            <h3>Valgrind Memory Check</h3>
            <div class="command-box">
                <span class="prompt">$</span> valgrind --leak-check=full --show-leak-kinds=all ./taskforge<br>
                <span class="prompt">$</span> valgrind --leak-check=full --track-origins=yes ./taskforge
            </div>

            <h3>Sample Output</h3>
            <div class="code-block">
                ==12345== HEAP SUMMARY:<br>
                ==12345==     in use at exit: 0 bytes in 0 blocks<br>
                ==12345==   total heap usage: 142 allocs, 142 frees, 12,345 bytes allocated<br>
                ==12345== <span style="color: #6a9955;">All heap blocks were freed -- no leaks are possible</span>
            </div>
        </section>

        <!-- Scenarios -->
        <section class="section">
            <h2><span class="icon">🎬</span> Runtime Scenarios</h2>
            
            <h3>Scenario 1: Production Pipeline Update</h3>
            <ul class="feature-list">
                <li>✅ Traverse nested production hierarchy</li>
                <li>✅ Change task states (Planning → Progressing → Finished)</li>
                <li>✅ Add urgent task with high priority</li>
                <li>✅ Demonstrate two different traversals</li>
            </ul>

            <h3>Scenario 2: Emergency Rush Order</h3>
            <ul class="feature-list">
                <li>✅ Apply priority decorator to low-priority task</li>
                <li>✅ Stack cost adjustment decorator</li>
                <li>✅ State changes during traversal</li>
                <li>✅ Decorated object participates in normal workflow</li>
            </ul>
        </section>

        <!-- Requirements Checklist -->
        <section class="section">
            <h2><span class="icon">✅</span> Requirements Checklist</h2>
            
            <div class="grid">
                <div style="grid-column: 1 / -1;">
                    <ul class="feature-list">
                        <li><strong>✅ Composite Pattern:</strong> ToDoItem (Component), ToDoTask (Leaf), ProductionGroup (Composite)</li>
                        <li><strong>✅ State Pattern:</strong> 5 concrete states with valid/invalid transitions</li>
                        <li><strong>✅ Decorator Pattern:</strong> PriorityDecorator and CostAdjustmentDecorator with stacking</li>
                        <li><strong>✅ Iterator Pattern:</strong> Standard and Cost-based traversals</li>
                        <li><strong>✅ 3+ Levels of Nesting:</strong> Root → Groups → Sub-groups → Tasks</li>
                        <li><strong>✅ Memory Safety:</strong> Virtual destructors, clear ownership, Valgrind clean</li>
                        <li><strong>✅ Docker Support:</strong> Working Dockerfile with all tools</li>
                        <li><strong>✅ Multiple Scenarios:</strong> Two non-trivial runtime demonstrations</li>
                    </ul>
                </div>
            </div>
        </section>

        <!-- Team -->
        <section class="section" style="border-left-color: #e74c3c;">
            <h2><span class="icon">👥</span> Team Information</h2>
            <div class="grid">
                <div class="grid-item">
                    <h4>Member 1</h4>
                    <p>Name: [Anchen Kruger]</p>
                    <p>Student #: [u25073703]</p>
                </div>
                <div class="grid-item">
                    <h4>Member 2</h4>
                    <p>Name: [Your Name]</p>
                    <p>Student #: [Student Number]</p>
                </div>
                <div class="grid-item">
                    <h4>Member 3</h4>
                    <p>Name: [Your Name]</p>
                    <p>Student #: [Student Number]</p>
                </div>
            </div>
        </section>
    </div>
</body>
</html>