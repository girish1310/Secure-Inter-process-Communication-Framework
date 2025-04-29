<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Secure Message Encryptor</title>
    <style>
        :root {
            --primary: #4361ee;
            --secondary: #3f37c9;
            --accent: #4895ef;
            --light: #f8f9fa;
            --dark: #212529;
            --success: #4cc9f0;
            --danger: #f72585;
            --border-radius: 8px;
            --box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }

        body {
            background-color: #f5f7fa;
            color: var(--dark);
            line-height: 1.6;
            padding: 20px;
        }

        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
        }

        .card {
            background: white;
            border-radius: var(--border-radius);
            box-shadow: var(--box-shadow);
            padding: 30px;
            margin-bottom: 20px;
        }

        h1 {
            color: var(--primary);
            text-align: center;
            margin-bottom: 20px;
            font-weight: 700;
        }

        .description {
            text-align: center;
            margin-bottom: 30px;
            color: #6c757d;
        }

        .form-group {
            margin-bottom: 20px;
        }

        label {
            display: block;
            margin-bottom: 8px;
            font-weight: 600;
            color: var(--dark);
        }

        input, textarea, select {
            width: 100%;
            padding: 12px;
            border: 1px solid #ced4da;
            border-radius: var(--border-radius);
            font-size: 16px;
            transition: border-color 0.3s;
        }

        input:focus, textarea:focus, select:focus {
            outline: none;
            border-color: var(--accent);
            box-shadow: 0 0 0 3px rgba(67, 97, 238, 0.25);
        }

        textarea {
            min-height: 120px;
            resize: vertical;
        }

        .btn {
            display: inline-block;
            background-color: var(--primary);
            color: white;
            border: none;
            padding: 12px 24px;
            border-radius: var(--border-radius);
            cursor: pointer;
            font-size: 16px;
            font-weight: 600;
            transition: all 0.3s;
            text-align: center;
            width: 100%;
        }

        .btn:hover {
            background-color: var(--secondary);
            transform: translateY(-2px);
            box-shadow: 0 6px 12px rgba(0, 0, 0, 0.1);
        }

        .btn-secondary {
            background-color: #6c757d;
        }

        .btn-secondary:hover {
            background-color: #5a6268;
        }

        .result-container {
            margin-top: 30px;
            display: none;
        }

        .result-box {
            background-color: #f8f9fa;
            border-radius: var(--border-radius);
            padding: 15px;
            margin-bottom: 15px;
            word-break: break-all;
            font-family: monospace;
        }

        .alert {
            padding: 15px;
            border-radius: var(--border-radius);
            margin-bottom: 20px;
            font-weight: 500;
        }

        .alert-success {
            background-color: #d1fae5;
            color: #065f46;
            border: 1px solid #a7f3d0;
        }

        .alert-danger {
            background-color: #fee2e2;
            color: #b91c1c;
            border: 1px solid #fecaca;
        }

        .tab-container {
            display: flex;
            margin-bottom: 20px;
            border-bottom: 1px solid #dee2e6;
        }

        .tab {
            padding: 10px 20px;
            cursor: pointer;
            border-bottom: 3px solid transparent;
            font-weight: 600;
            color: #6c757d;
        }

        .tab.active {
            color: var(--primary);
            border-bottom-color: var(--primary);
        }

        .tab-content {
            display: none;
        }

        .tab-content.active {
            display: block;
        }

        .copy-btn {
            background-color: var(--accent);
            color: white;
            border: none;
            padding: 8px 15px;
            border-radius: var(--border-radius);
            cursor: pointer;
            font-size: 14px;
            margin-top: 10px;
            transition: background-color 0.3s;
        }

        .copy-btn:hover {
            background-color: #3a86ff;
        }

        .key-display {
            font-family: monospace;
            background-color: #f0f0f0;
            padding: 10px;
            border-radius: var(--border-radius);
            margin: 10px 0;
            word-break: break-all;
        }

        @media (max-width: 768px) {
            .container {
                padding: 10px;
            }
            
            .card {
                padding: 20px;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>🔐 Secure Message Encryptor</h1>
        <p class="description">Encrypt your message and decrypt it with the correct key.</p>

        <div class="card">
            <div class="tab-container">
                <div class="tab active" onclick="switchTab('encrypt')">Encrypt Message</div>
                <div class="tab" onclick="switchTab('decrypt')">Decrypt Message</div>
            </div>

            <div id="encrypt-tab" class="tab-content active">
                <div class="form-group">
                    <label for="message">Your Message:</label>
                    <textarea id="message" placeholder="Enter the message you want to encrypt..."></textarea>
                </div>

                <button id="encrypt-btn" class="btn">🔒 Encrypt Message</button>

                <div id="encrypt-result" class="result-container">
                    <div class="alert alert-success">
                        <strong>🔹 Message Encrypted Successfully!</strong>
                    </div>

                    <div class="form-group">
                        <label>Encrypted Data:</label>
                        <div class="result-box" id="encrypted-data"></div>
                        <button class="copy-btn" onclick="copyToClipboard('encrypted-data')">📋 Copy Encrypted Data</button>
                    </div>

                    <div class="form-group">
                        <label>Your Unique Encryption Key:</label>
                        <div class="key-display" id="encryption-key"></div>
                        <small style="color: #6c757d;">Save this key to decrypt your message later</small>
                        <button class="copy-btn" onclick="copyToClipboard('encryption-key')">📋 Copy Key</button>
                    </div>
                </div>
            </div>

            <div id="decrypt-tab" class="tab-content">
                <div class="form-group">
                    <label for="encrypted-input">Encrypted Data:</label>
                    <textarea id="encrypted-input" placeholder="Paste your encrypted data here..."></textarea>
                </div>

                <div class="form-group">
                    <label for="user-key">Decryption Key:</label>
                    <input type="password" id="user-key" placeholder="Enter your encryption key">
                </div>

                <button id="decrypt-btn" class="btn">🔓 Decrypt Message</button>

                <div id="decrypt-result" class="result-container">
                    <div class="alert" id="decrypt-alert"></div>

                    <div class="form-group">
                        <label>Decrypted Message:</label>
                        <div class="result-box" id="decrypted-message"></div>
                        <button class="copy-btn" onclick="copyToClipboard('decrypted-message')">📋 Copy</button>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <script>
        // Generate a random 16-character key
        function generateRandomKey() {
            const chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
            let result = '';
            for (let i = 0; i < 16; i++) {
                result += chars.charAt(Math.floor(Math.random() * chars.length));
            }
            return result;
        }

        // Tab switching function
        function switchTab(tabName) {
        
            document.querySelectorAll('.tab-content').forEach(content => {
                content.classList.remove('active');
            });
            
            // Deactivate all tabs
            document.querySelectorAll('.tab').forEach(tab => {
                tab.classList.remove('active');
            });
            
            // Activate selected tab
            document.getElementById(`${tabName}-tab`).classList.add('active');
            document.querySelector(`.tab[onclick="switchTab('${tabName}')"]`).classList.add('active');
            
            // // Clear results when switching tabs
            // document.getElementById('encrypt-result').style.display = 'none';
            // document.getElementById('decrypt-result').style.display = 'none';
        }

        // XOR Encryption function that outputs hex
        function xorEncryptToHex(msg, key) {
            let output = '';
            for (let i = 0; i < msg.length; i++) {
                const charCode = msg.charCodeAt(i) ^ key.charCodeAt(i % key.length);
                // Convert to 2-digit hexadecimal representation
                output += ('0' + charCode.toString(16)).slice(-2);
            }
            return output;
        }

        // XOR Decryption function for hex input
        function xorDecryptFromHex(hexMsg, key) {
            let output = '';
            // Verify even length (each byte is 2 hex digits)
            if (hexMsg.length % 2 !== 0) {
                throw new Error('Invalid hex length');
            }
            
            // Split hex string into pairs of two characters
            for (let i = 0; i < hexMsg.length; i += 2) {
                const hexByte = hexMsg.substr(i, 2);
                if (!/^[0-9a-fA-F]{2}$/.test(hexByte)) {
                    throw new Error('Invalid hex character');
                }
                const charCode = parseInt(hexByte, 16);
                const decryptedChar = charCode ^ key.charCodeAt((i/2) % key.length);
                output += String.fromCharCode(decryptedChar);
            }
            return output;
        }

        // Encrypt button handler
        document.getElementById('encrypt-btn').addEventListener('click', () => {
            const message = document.getElementById('message').value;
            if (!message) {
                alert('Please enter a message to encrypt');
                return;
            }

            // Generate a new random key for each encryption
            const encryptionKey = generateRandomKey();
            const encrypted = xorEncryptToHex(message, encryptionKey);
            
            // Display results
            document.getElementById('encrypted-data').textContent = encrypted;
            document.getElementById('encryption-key').textContent = encryptionKey;
            document.getElementById('encrypt-result').style.display = 'block';
        });

        // Decrypt button handler
        document.getElementById('decrypt-btn').addEventListener('click', () => {
            const encryptedInput = document.getElementById('encrypted-input').value.trim();
            const userKey = document.getElementById('user-key').value.trim();

            if (!encryptedInput) {
                alert('Please provide the encrypted data');
                return;
            }
            
            if (!userKey) {
                alert('Please provide the decryption key');
                return;
            }

            try {
                const decrypted = xorDecryptFromHex(encryptedInput, userKey);
                
                document.getElementById('decrypted-message').textContent = decrypted;
                document.getElementById('decrypt-alert').textContent = '✅ Correct key! Message decrypted successfully.';
                document.getElementById('decrypt-alert').className = 'alert alert-success';
            } catch (e) {
                document.getElementById('decrypted-message').textContent = '';
                document.getElementById('decrypt-alert').textContent = '❌ Incorrect key or invalid data! Decryption failed.';
                document.getElementById('decrypt-alert').className = 'alert alert-danger';
            }
            
            document.getElementById('decrypt-result').style.display = 'block';
        });

        // [Previous JavaScript code remains exactly the same]
        
        // Add this to handle potential CORS issues when testing locally
        document.addEventListener('DOMContentLoaded', function() {
            if (window.location.protocol === 'file:') {
                alert('Note: For best results, view this page through a web server.\nLocal file access may limit some functionality.');
            }
        });

        // Copy to clipboard function
        function copyToClipboard(elementId) {
            const element = document.getElementById(elementId);
            const text = element.textContent;
            
            navigator.clipboard.writeText(text).then(() => {
                const originalText = element.textContent;
                element.textContent = 'Copied to clipboard!';
                setTimeout(() => {
                    element.textContent = originalText;
                }, 2000);
            }).catch(err => {
                console.error('Failed to copy: ', err);
            });
        }
    </script>
</body>
</html>
