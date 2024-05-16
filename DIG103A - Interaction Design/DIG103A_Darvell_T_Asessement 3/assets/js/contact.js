/*=============== EMAIL JS ===============*/
// Using Emailjs.com to act as a connecting platform.
const contactForm = document.getElementById('contact-form'),
      contactMessage = document.getElementById('contact-message');

      const sendEmail = (e) => {
        e.preventDefault();
        
        // emailjs.sendForm('your_serviceID', 'your_templateId', '#contact-form', 'your_publicKey')
        emailjs.sendForm('service_3uaanue', 'template_1tjygxo', '#contact-form', 'FFUXXgT9iWuyNPxDe')
            .then((result) => {
                console.log('SUCCESS!', result.text);
                // Show Sent Message
                contactMessage.textContent = 'Message sent successfully ✅';
    
                // Remove message after five seconds
                setTimeout(() => {
                    contactMessage.textContent = '';
                }, 5000);
    
                // Clear input fields
                contactForm.reset();
            }, (error) => {
                console.log('FAILED...', error.text);
                // Show error message
                contactMessage.textContent = 'Message not sent (service error) ❌';
            });
    }

contactForm.addEventListener('submit', sendEmail);